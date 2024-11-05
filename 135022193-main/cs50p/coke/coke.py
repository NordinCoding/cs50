def main():

    amount_due = 50
    valid_coins = [5, 10, 25]

    while amount_due > 0:
        print(f"Amount Due: {amount_due}")

        inserted = int(input("Insert Coin: "))
        if inserted in valid_coins:
            amount_due = amount_due - inserted

    print(f"Change Owed: {abs(amount_due)}")


main()
