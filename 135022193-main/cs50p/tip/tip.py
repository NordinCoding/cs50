def main():
    dollars = dollars_to_float(input("How much was the meal? "))
    print(dollars)
    percent = percent_to_float(input("What percentage would you like to tip? "))
    print(percent)
    tip = dollars * percent
    print(f"Leave ${tip:.2f}")


def dollars_to_float(d):
    amount = d.strip('$')
    return float(amount)


def percent_to_float(p):
    percentage = float(p.strip('%'))
    return percentage / 100



main()
