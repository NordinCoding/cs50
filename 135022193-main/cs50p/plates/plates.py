def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    length = len(s)

    # check if the string is min of 2 characters and max of 6 characters
    if length < 2 or length > 6:
        return False

    # check if the first 2 character are alphabetical
    if s[0].isalpha() == True and s[1].isalpha() == True:
        pass
    else:
        return False

    if not numCheck(s):
        return False

    if not punctuationCheck(s):
        return False

    return True


def numCheck(s):

    check = ''

    for i in range(0, len(s)):
        if s[i].isdigit():
            check = s[i:]
            break

    if len(check) == 0:
        return True

    if check[0] == '0':
        return False

    if not check.isdigit():
        return False

    return True


def punctuationCheck(s):
    punctuation = "!\"#$%&'()*+,-./:;<=>?@[]^_`{|}~"

    for i in range(0, len(s)):
        if s[i] in punctuation:
            return False
        elif s[i] == ' ':
            return False

    return True


main()
