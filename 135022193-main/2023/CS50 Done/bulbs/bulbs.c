#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Delcaring the variables
    int j;
    int array[8];
    int ascii;
    string ch;
    ch = get_string("enter: ");
    // Loop  to convert every character of 'ch' into its ascii value
    for (int i = 0, len = strlen(ch); i < len; i++)
    {
        ascii = ch[i];
        // Loop for converting the ascii values into binary code
        for (j = 0; j < 7; j++)
        {
            int r = ascii % 2;
            ascii = ascii / 2;
            array[j] = r;
        }
        // Loop to print the binary array in reverse with the print_bulb function
        for (j = 7; j >= 0; j--)
        {
            print_bulb(array[j]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}