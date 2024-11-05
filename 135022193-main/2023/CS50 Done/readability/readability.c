#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);

    float L = letters / words * 100;
    float S = sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if(index>=1 && index<=16)
    {
        printf("Grade %g\n", round(index));
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}


float count_letters(string text)
{
    float letters = 0;

    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}


float count_words(string text)
{
    float words = 0;

    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;

}


float count_sentences(string text)
{
    float sentences = 0;

    for(int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

    }
    return sentences;
}