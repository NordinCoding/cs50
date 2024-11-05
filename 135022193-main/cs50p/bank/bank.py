def main():
    userIn = input("Greeting: ")
    check = userIn.lower().strip()

    if "hello" in check:
        print("$0")
    elif check[0] == "h":
        print("$20")
    else:
        print("$100")

main()
