#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <cs50.h>


//test key: NQXPOMAFTRHLZGECYJIUWSKDVB


int main(int argc, char *argv[])
{

    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    // check if command line argument is being used
    if(argc != 2)
    {
        printf("Usage: ./substitution (key)\n");

        return 1;
    }

    int len = strlen(argv[1]);

    char *key = argv[1];

    //make key all lowercase
    for(int i = 0; i < len; i++)
    {
        key[i] = tolower(key[i]);
    }


    // check if the length of the key is correct
    if (len != 26)
    {
        printf("Key has to be 26 characters\n");

        return 1;
    }

    // check if every char in the key is alphabetical
    for (int i = 0; i < len; i++)
    {
        bool found = false;

        if (isalpha(key[i]) == 0)
        {
            printf("Every character should be alphabetic\n");

            return 1;
        }

        //Check if every letter of the alphabet is in KEY
        for (int j = 0; j < len; j++)
        {
            if(alphabet[i] == key[j])
            {
                found = true;
            }
        }
        if(found == false)
        {
            printf("Key should contain every letter\n");

            return 1;
        }
    }

    char *plaintext = get_string("plaintext: ");
    char *ciphertext = plaintext;

    int plainlen = strlen(plaintext);

    //conversion therapy
    for(int i = 0; i < plainlen; i++)
    {
        int index;

        if (isupper(plaintext[i]) != 0)
        {
            plaintext[i] = tolower(plaintext[i]);

            index = plaintext[i] - 97;

            ciphertext[i] = toupper(key[index]);
        }
        else if (islower(plaintext[i]) != 0)
        {
            index = plaintext[i] - 97;

            ciphertext[i] = key[index];
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s", ciphertext);
    printf("\n");

    return 0;
}
