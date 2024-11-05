#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char replace(char plain, string key);

int main(int argc, string argv[])
{
    string plaintext;
    string ciphertext = NULL;
    string key = argv[1];

    if (argc != 2)
    {
        printf("Correct usage ./substitution key of 26 characters\n");
        return 1;
    }
    if (strlen(key) != 26)
    {
        printf("Correct usage ./substitution key of 26 characters\n");
        return 1;
    }
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == 0)
        {
            printf("Correct usage ./substitution key of 26 characters\n");
            return 1;
        }
    }
    for (int i = 0; i < strlen(key); i++)
    {
        int sum = 0;
        for (int j = 0; j < strlen(key); j++)
        {
            if (key[i] == key[j])
            {
                sum++;
            }
            if (sum > 1)
            {
                printf("Correct usage ./substitution key of 26 characters\n");
                return 1;
            }
        }
    }

    plaintext = get_string("Plaintext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        plaintext[i] = replace(plaintext[i], key);
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}

char replace(char plain, string key)
{
    string alphabetLow = "abcdefghijklmnopqrstuvwxyz";
    string alphabetUp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char c;
    int index;

    for (int i = 0; i < strlen(alphabetLow); i++)
    {
        if (isalpha(plain) == 0)
        {
            return plain;
        }
        else if (plain == alphabetLow[i] || plain == alphabetUp[i])
        {
            if (plain >= 97 && plain <= 122)
            {
                c = (tolower(key[i]));
                return c;
            }
            else if (plain >= 65 && plain <= 90)
            {
                c = (toupper(key[i]));
                return c;
            }
        }
    }
    return 0;
}
