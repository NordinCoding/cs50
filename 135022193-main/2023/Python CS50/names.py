import sys

names = ["Bill", "Charlie", "Fred"]

name = input("Name: ")

if name in names:
    sys.exit("Found")

sys.exit("Not found")
