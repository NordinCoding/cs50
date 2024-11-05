import csv
import sys


def main():

    # TODO: DONE!!!!
    if len(sys.argv) > 3:
        print("WRONG SIZE BUCKO!!!!")

    # TODO: DONE!!!!
    database = []
    with open(sys.argv[1]) as dbFile:
        reader = csv.DictReader(dbFile)
        for row in reader:
            # DATABASE CONTAINS THE FILE CONTENTS
            database.append(row)

    # TODO: DONE!!!!!
    with open(sys.argv[2], 'r') as sqFile:
        # SEQUENCE CONTAINS THE FILE CONTENTS
        sequence = sqFile.read()

    # Create list of STRs
    STRs = []
    counter = 0
    for i in database[0]:
        if counter != 0:
            STRs.append(i)
        counter += 1

    # TODO: Find longest match of each STR in DNA sequence
    longest_s = []
    for STR in STRs:
        longest = longest_match(sequence, STR)
        longest_s.append(longest)

    # TODO: Check database for matching profiles

    for row in database:
        check = (list(row.values()))
        del check[0]

        counter = 0
        length = len(longest_s)

        for i in range(length):
            if longest_s[i] == int(check[i]):
                counter += 1

            if counter == length:
                print(row["name"])
                return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
