def main():
    userIn = input("What is the Answer to the Great Question of Life, the Universe, and Everything? ")

    valid = ["42", "forty-two", "forty two"]

    if userIn.lower().strip() in valid:
        print("Yes")
    else:
        print("No")

    return 0


main()
