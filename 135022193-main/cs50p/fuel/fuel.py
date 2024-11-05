def main():

    # keep prompting until the desired values are input
    while True:
        level = input("Fraction: ")

        if '/' in level:
            levels = level.split('/')
            x = levels[0]
            y = levels[1]

            # check if both variables are integers
            if checkInt(x, y):
                x = int(x)
                y = int(y)

                #check if X is not greater than Y and Y is greater than 0
                if y >= x and y > 0:
                    break

    fraction = round(x / y * 100)

    #if less than 1% output E
    if fraction <= 1:
        print("E")
    #if greater than 99% output F
    elif fraction >= 99:
        print("F")
    else:
        fraction = str(fraction)
        print(f"{fraction}%")

    return 0































































def checkInt(x, y):
    try:
        x = int(x)
    except ValueError:
        return False

    try:
        y = int(y)
    except ValueError:
        return False

    return True



main()
