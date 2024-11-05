def main():
        print_column()



















def print_column():
     height = get_height()
     print_hash(height)


def get_height():
    while True:
        try:
            n = int(input("height: "))
            if n > 0:
                return n
        except ValueError:
             print("Not an integer")


def print_hash(height):
    for i in range(height):
        print("#")


main()
