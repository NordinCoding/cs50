from cs50 import get_float

quarters = 25
dimes = 10
nickels = 5
pennies = 1

coinsList = [quarters, dimes, nickels, pennies]

while True:
    change = get_float("change: ")
    if change >= 0:
        change = int(change * 100)
        break

for i in range(len(coinsList)):
    tmpCoins = change // coinsList[i]
    coins = coins + tmpCoins
    change = change - (tmpCoins * coinsList[i])

print(coins)
