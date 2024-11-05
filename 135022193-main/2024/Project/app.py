import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required
from scrapers import bol_scraper

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db = SQL("sqlite:///discounts.db")

@app.route("/testing")
def testing():
    return render_template("testing.html")

@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    # Get all productID's from current user
    userProducts = db.execute("SELECT * FROM userProducts WHERE userID = ?", session["user_id"])
    products= []

    # For every product in Users list update the values and send them to front-end
    for userProduct in userProducts:
        productID = userProduct["productID"]

        # Create list of updated products
        product = db.execute("SELECT * FROM products WHERE id = ?", productID)
        products.append(product[0])

    # Send updated products to index.html
    return render_template("index.html", products=products)

@app.route('/api/get_prices', methods=["GET"])
@login_required
def get_prices():
    # Get all productID's from current user
    userProducts = db.execute("SELECT * FROM userProducts WHERE userID = ?", session["user_id"])
    updatedProducts = []

    # For every product in Users list update the values and send them to front-end
    for userProduct in userProducts:

        # Get current productID and get the URL of that product
        productID = userProduct["productID"]
        URL = db.execute("SELECT URL FROM products WHERE id = ?", productID)[0]['URL']

        # Get updates values using scraper and update database values
        dictValues = bol_scraper(URL)
        db.execute("UPDATE products SET name = ?, ogPrice = ?, currentPrice = ? WHERE id = ?",
                    dictValues["name"], float(dictValues["ogPrice"]), float(dictValues["currentPrice"]), productID)

        # Create list of updated products
        updatedProduct = db.execute("SELECT * FROM products WHERE id = ?", productID)
        updatedProducts.extend(updatedProduct)

    return jsonify(updatedProducts)

@app.route('/removeRow', methods=["POST"])
@login_required
def removeRow():
    rowData = request.get_json()
    productData = db.execute("SELECT * FROM products WHERE name = ?", rowData['id'])
    db.execute("DELETE FROM userproducts WHERE userID = ? AND productID = ?",
               session['user_id'], productData[0]['id'])
    return '', 204


@app.route("/register", methods=["GET", "POST"])
def register():

    session.clear()

    if request.method == "POST":
        # Check if username, password and confirm text fields are filled in
        if not request.form.get("username"):
            return apology("Must provide username", 400)
        if not request.form.get("password"):
            return apology("Must provide password", 400)
        if not request.form.get("confirmation"):
            return apology("Must confirm password", 400)

        # Check if username is unique
        username = request.form.get("username")
        usercheck = db.execute("SELECT * FROM users where username = ?", username)
        print(usercheck)
        if len(usercheck) != 0:
            return apology("username already exists", 400)


        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        # Check if password and confirmation are equal
        if password != confirmation:
            return apology("Password and confirm password are not equal", 400)

        # Generate password Hash and insert data into the database
        passwordHash = generate_password_hash(password, method='pbkdf2', salt_length=16)
        db.execute("INSERT INTO users (username, passwordHash) VALUES(?, ?)", username, passwordHash)

        return redirect("/")

    return render_template("register.html")


@app.route("/login", methods=["GET", "POST"])
def login():

    session.clear()

    if request.method == "POST":
        # Check if all fields are filled
        if not request.form.get("username"):
            return apology("Must provide username", 400)
        if not request.form.get("password"):
            return apology("Must provide password", 400)

        # Check if username is in database
        username = request.form.get("username")
        userCheck = db.execute("SELECT * FROM users WHERE username = ?", username)
        if len(userCheck) != 1:
            return apology("Username doesn't exist", 400)

        # Check if password is attached to username
        password = request.form.get("password")
        if not check_password_hash(userCheck[0]["passwordHash"], password):
            return apology("Incorrect password", 400)

        # set session id to the user id
        session["user_id"] = userCheck[0]["id"]
        print(session["user_id"])

        return redirect("/")

    return render_template("login.html")


@app.route("/logout")
def logout():

    session.clear()

    return redirect("/")


@app.route("/getURL", methods=["GET", "POST"])
@login_required
def getURL():
    if request.method == "POST":
        # Scrape values from website and insert them into database
        URL = request.form.get("URL")
        if "https://www.bol.com/nl/nl/p" not in URL:
            return apology("invalid URL", 400)

        dictValues = bol_scraper(URL)

        try:
            db.execute("INSERT INTO products (URL, name, ogPrice, currentPrice) VALUES(?, ?, ?, ?)",
                    URL, dictValues["name"], float(dictValues["ogPrice"]), float(dictValues["currentPrice"]))
        except TypeError:
            return apology("invalid URL", 400)

        # Get the ID of the product just inserted
        productID = db.execute("SELECT id FROM products WHERE name = ?", dictValues["name"])

        # Insert userID and productID together into database
        db.execute("INSERT INTO userProducts (userID, productID) VALUES(?, ?)",
                   session["user_id"], productID[0]["id"])

        return redirect("/")

    return render_template("getURL.html")
