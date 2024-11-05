#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    //prompt user for size between 0 and 9
    do
    {
        n = get_int("size: ");
    }
    while (n < 1 || n > 8);

    //loop for creating the rows
    for (int i = 0; i < n; i++)
    {
        //loop for creating the first blank spaces
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }
        //loop for creating the first pyramid of hashes
        for (int p = 0; p <= i; p++)
        {
            printf("#");
        }
        printf("  ");
        //loop for creating the second pyramid of hashes
        for (int e = 0; e <= i; e++)
        {
            printf("#");
        }
        printf("\n");
    }
}