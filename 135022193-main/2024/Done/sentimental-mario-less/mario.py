import cs50


def main():
    n = get_height()
    for i in range(n):
        print(" " * (n - (i + 1)) + "#" * (i + 1))


def get_height():
    while True:
        n = cs50.get_int("Height: ")
        if n > 0 and n < 9:
            return n


main()
