#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    string plaintext;
    string new_code = NULL;
    int key;

    if (argc != 2)
    {
        printf("correct usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            return 1;
        }
    }

    if (only_digits(argv[1]) == true)
    {
        plaintext = get_string("plaintext: ");

        key = atoi(argv[1]);

        for (int i = 0; i < strlen(plaintext); i++)
        {
            plaintext[i] = rotate(plaintext[i], key);
        }
        printf("ciphertext: %s\n", plaintext);
    }
    return 0;
}

char rotate(char c, int key)
{
    if (c >= 65 && c <= 90)
    {
        key = key % 26;
        if (c + key > 90)
        {
            key = c + key - 90;
            c = 64 + key;
            return c;
        }
        c = c + key;
        return c;
    }
    else if (c >= 97 && c <= 122)
    {
        key = key % 26;
        if (c + key > 122)
        {
            key = c + key - 122;
            c = 96 + key;
            return c;
        }
        c = c + key;
        return c;
    }
    else
    {
        return c;
    }
    return 0;
}

bool only_digits(string s)
{
    int digit;
    int sum = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            sum++;
        }
    }
    if (sum == strlen(s))
    {
        return true;
    }
    else
    {
        printf("Usage ./caesar key\n");
        return false;
    }
}
