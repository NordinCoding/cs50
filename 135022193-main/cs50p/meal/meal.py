def main():
    time = input("What time is it? ")
    convertedTime = convert(time)
    if convertedTime >= 7 and convertedTime <= 8:
        print("breakfast time")
    elif convertedTime >= 12 and convertedTime <= 13:
        print("lunch time")
    elif convertedTime >= 18 and convertedTime <= 19:
        print("dinner time")


def convert(time):
    splitTime = time.split(":")
    minutes = int(splitTime[1]) / 60

    return float(splitTime[0]) + minutes


if __name__ == "__main__":
    main()
