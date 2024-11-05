#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main()
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    float L = letters / words * 100;
    float S = sentences / words * 100;

    float tmp = 0.0588 * L - 0.296 * S - 15.8;
    int index = round(tmp);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int count_letters(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            sum++;
        }
    }
    return sum;
}

int count_sentences(string text)
{
    int sum = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sum++;
        }
    }
    return sum;
}
