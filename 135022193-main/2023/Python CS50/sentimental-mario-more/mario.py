def main():
    Height = get_height()
    for i in range(Height):
        print(" " * (Height - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))


def get_height():
    while True:
        try:
            Height = int(input("Height: "))
            if Height > 0 and Height < 9:
                return Height
        except ValueError:
            print("Not an integer")


main()
