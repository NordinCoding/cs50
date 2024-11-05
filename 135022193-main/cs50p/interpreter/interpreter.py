def main():
    expression = input("Expression: ")

    math = expression.split()

    x = float(math[0])
    y = math[1]
    z = float(math[2])

    if y == "+":
        print(x + z)
    elif y == "-":
        print(x - z)
    elif y == "*":
        print(x * z)
    elif y == "/":
        print(x / z)


main()
