#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    string plaintext;
    char ciphertext[50];
    int i;
    int len;

    // if statement to check if there is more than one extra command line argument
    if (argc != 2 || argc < 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char *inputString = argv[1];

    // loop for detecting any non digit characters in the command line argument argv[1]
    for (i = 0; inputString[i] != '\0'; i++)
    {
        if (isdigit(inputString[i]))
        {
            printf("");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    // if statement to detect if argv[1] is a digit, else returning a usage statement
    if (isdigit(*argv[1]))
    {
        printf("");
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // get plaintext
    plaintext = get_string("plaintext:  ");

    // enchipher get ascii value, get the key % 26, key + remainder is new ascii value
    for (i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    // printing out ciphertext, new line and returning 0
    printf("ciphertext: %s", ciphertext);
    printf("\n");
    return 0;
}