def main():
    message = input("Input: ")

    converted = convert(message)

    print(f"Output: {converted}")


def convert(message):
    converted = ''
    vowels=['a', 'e', 'i', 'o', 'u']

    for i in range(0, len(message)):
        if message[i].lower() in vowels:
            pass
        else:
            converted = converted + message[i]

    return converted


main()
