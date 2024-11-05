from cs50 import get_string, get_int


def main():

    i = 0
    sum1 = 0
    sum2 = 0
    card = get_int("number: ")
    cardCopy = card

# create the sums for checking cards validity
    while card != 0:
        digit = card % 10
        if i % 2 == 0:
            sum2 += digit
        elif i % 2 != 0:
            digit = digit * 2
            if digit >= 10:
                tmp = list(str(digit))
                for j in range(len(tmp)):
                    digit = int(tmp[j])
                    sum1 += digit
            else:
                sum1 += digit

        card //= 10
        i += 1

    sum = sum1 + sum2
    tmp = list(str(sum))

    # check if sums last digit is 0
    if tmp[len(tmp) - 1] != '0':
        print("INVALID")
        return 0

# declare variables for checking validity
    VISA = cardCopy
    while (VISA >= 10):
        VISA //= 10

    AMEX = cardCopy
    while (AMEX >= 100):
        AMEX //= 10

    MASTERCARD = cardCopy
    while (MASTERCARD >= 100):
        MASTERCARD //= 10

    # check validity of VISA
    if i == 16 and VISA == 4 or i == 13 and VISA == 4:
        print("VISA")
        return 0

    # check validity of AMEX
    elif i == 15 and AMEX == 34 or AMEX == 37:
        print("AMEX")
        return 0

    # check validity of MASTERCARD
    elif i == 16 and MASTERCARD >= 51 and MASTERCARD <= 55:
        print("MASTERCARD")
        return 0

    else:
        print("INVALID")


main()
