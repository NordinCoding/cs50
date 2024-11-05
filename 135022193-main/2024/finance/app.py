import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    sum = 0
    purchases = db.execute("SELECT * FROM portfolios WHERE userid = ?", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

    for purchase in purchases:
        sum = sum + (purchase['price'] * purchase['shares'])

    try:
        sum = sum + cash[0]['cash']
    except (IndexError):
        return redirect("/login")

    return render_template("index.html", purchases=purchases, cash=cash, sum=round(sum, 2))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Please fill in Stock", 400)
        if not request.form.get("shares"):
            return apology("Please fill in Shares", 400)

        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        try:
            shares = int(shares)
        except ValueError:
            return apology("Can only buy whole shares", 400)

        dict = lookup(symbol)
        if dict == None:
            return apology("Symbol does not exist", 400)
        userCash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        userCash = userCash[0]["cash"]
        userPrice = dict["price"] * shares

        if dict == None:
            return apology("Stock not Found", 400)
        if shares < 1:
            return apology("Shares less than 1", 400)
        if userPrice > userCash:
            return apology("Youre broke as fuck", 400)

        transactions = db.execute("SELECT * FROM transactions WHERE userid = ?", session["user_id"])
        with open("transactions.txt", "w") as f:
            for transaction in transactions:
                for key, value in transaction.items():
                    f.write(str(key) + ': ' + str(value) + '\n')
                f.write("\n")
        portfolios = db.execute("SELECT * FROM portfolios WHERE userid = ?", session["user_id"])
        with open("portfolios.txt", "w") as f:
            for portfolio in portfolios:
                for key, value in portfolio.items():
                    f.write(str(key) + ': ' + str(value) + '\n')
                f.write("\n")

        db.execute("INSERT INTO transactions (userid, symbol, price, shares, transaction_type) VALUES(?, ?, ?, ?, ?)",
                   int(session["user_id"]), dict["symbol"], dict["price"], shares, "BUY")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = cash[0]["cash"]
        cash = cash - (dict["price"] * shares)

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

        # Make list of already owned symbols
        symbolsList = []
        for portfolio in portfolios:
            symbolsList.append(portfolio["symbol"])

        # check if portfolio if empty, if true add new symbol to portfolio
        if len(portfolios) == 0:
            db.execute("INSERT INTO portfolios (userid, symbol, shares, price) VALUES(?, ?, ?, ?)",
                       int(session["user_id"]), dict["symbol"], shares, dict["price"])
        else:
            # check if symbol is in portfolio.
            for portfolio in portfolios:
                if dict["symbol"] in symbolsList:
                    shares = shares + portfolio["shares"]
                    db.execute("UPDATE portfolios SET shares = ? WHERE (symbol) = ? AND userid = ?",
                               shares, symbol, session["user_id"])
                    break
                # else insert new symbol into not empty portfolio.
                else:
                    db.execute("INSERT INTO portfolios (userid, symbol, shares, price) VALUES (?, ?, ?, ?)",
                               int(session["user_id"]), dict["symbol"], shares, dict["price"])
                    break
        return redirect("/")

    """Buy shares of stock"""
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    transactions = db.execute("SELECT * FROM transactions where userid = ?", session["user_id"])
    """Show history of transactions"""

    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("Must provide symbol", "400")

        symbol = request.form.get("symbol")
        dict = lookup(symbol)
        if dict == None:
            return apology("Symbol does not exist", "400")
        dict["price"] = usd(dict["price"])

        return render_template("quoted.html", dict=dict)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():

    session.clear()

    if request.method == "POST":

        if not request.form.get("username"):
            return apology("Must provide username", "400")
        elif not request.form.get("password"):
            return apology("Must provide password", "400")

        username = request.form.get("username")

        password = request.form.get("password")
        confirmPassword = request.form.get("confirmation")

        if confirmPassword != password:
            return apology("Passwords are not the same")

        hash = generate_password_hash(password, method='pbkdf2', salt_length=16)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
        except:
            return apology("Username already exists")

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    portfolios = db.execute("SELECT * FROM portfolios WHERE userid = ?", session["user_id"])
    if request.method == "POST":
        # Check if every requirement is met
        if not request.form.get("symbol"):
            return apology("Please choose a symbol", 400)
        if not request.form.get("shares"):
            return apology("Please fill in the amount of shares", 400)

        # Get input values
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Return apology if shares is non positive
        if shares < 1:
            return apology("Shares needs to be greater than 0", 400)

        # Loop through portfolios until portfolio of current symbol is found
        for portfolio in portfolios:
            if symbol in portfolio["symbol"]:

                if shares > portfolio["shares"]:
                    return apology("Not enough shares")

                # Create new cash value by creating sum of existing cash + sold stocks and update database
                userCash = db.execute("SELECT cash from USERS where id = ?", session["user_id"])
                userCash = float(userCash[0]["cash"])
                sellCash = shares * float(portfolio["price"])
                cash = userCash + sellCash

                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

                newShares = int(portfolio["shares"]) - shares
                db.execute("UPDATE portfolios SET shares = ? WHERE (symbol) = ? AND userid = ?",
                           newShares, symbol, session["user_id"])

                if newShares <= 0:
                    db.execute("DELETE FROM portfolios WHERE (symbol) = ? AND userid = ?",
                               symbol, session["user_id"])

                db.execute("INSERT INTO transactions (userid, symbol, price, shares, transaction_type) VALUES(?, ?, ?, ?, ?)",
                           int(session["user_id"]), symbol, portfolio["price"], shares, "SELL")

                return redirect("/")

    """Sell shares of stock"""
    return render_template("sell.html", portfolios=portfolios)
