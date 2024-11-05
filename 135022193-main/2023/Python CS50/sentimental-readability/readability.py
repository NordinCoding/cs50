from cs50 import get_string


def main():
    letter_count = 0
    words_count = 1
    sentences_count = 0
    text = get_string("Text: ")
    letter_count = count_letters(text, letter_count)
    words_count = count_words(text, words_count)
    sentences_count = count_sentences(text, sentences_count)
    print_grade(letter_count, words_count, sentences_count)


def count_letters(text, letter_count):
    for i in range(len(text)):
        if text[i].isalpha() == True:
            letter_count += 1
    return letter_count


def count_words(text, words_count):
    for i in range(len(text)):
        if text[i] == " ":
            words_count += 1
    return words_count


def count_sentences(text, sentences_count):
    for i in range(len(text)):
        if text[i] in [".", "!", "?"]:
            sentences_count += 1
    return sentences_count


def print_grade(letter_count, words_count, sentences_count):
    L = letter_count / words_count * 100
    S = sentences_count / words_count * 100
    index = 0.0588 * L - 0.296 * S - 15.8
    index = round(index)
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")


main()
