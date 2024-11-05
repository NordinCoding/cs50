from cs50 import get_string

letters = 0
words = 1
sentences = 0


def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # L is average number of letters per 100 words
    L = letters / words * 100

    # S is average number of senteces per 100 words
    S = sentences / words * 100

    grade = 0.0588 * L - 0.296 * S - 15.8
    grade = round(grade)

    print_grade(grade)


def count_letters(text):
    sumL = 0

    for i in range(len(text)):
        if (text[i].isalpha() == True):
            sumL += 1
    return sumL


def count_words(text):
    sumW = 1

    for i in range(len(text)):
        if (text[i] == " "):
            sumW += 1
    return sumW


def count_sentences(text):
    sumS = 0

    for i in range(len(text)):
        if (text[i] == "." or text[i] == "!" or text[i] == "?"):
            sumS += 1
    return sumS


def print_grade(grade):
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


main()
