from cs50 import get_float


def main():
    coins = 0

    change = int(get_change() * 100)
    coins = get_coins(change)
    print(coins)


def get_change():
    while True:
        change = get_float("Change: ")
        if change > 0:
            return change


def get_coins(change):
    coins = 0
    # quarters
    while change >= 25:
        change -= 25
        coins += 1
    # dimes
    while change >= 10:
        change -= 10
        coins += 1
    # nickels
    while change >= 5:
        change -= 5
        coins += 1
    # pennies
    while change >= 1:
        change -= 1
        coins += 1
    return coins


main()
