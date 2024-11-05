#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


int main (void)
{
    FILE *output = fopen(penis.txt, "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char *word = get_string("give me a word: ");

    fwrite(word, strlen(word), 1, output);
}