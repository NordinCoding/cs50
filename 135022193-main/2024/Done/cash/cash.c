#include <cs50.h>
#include <stdio.h>

int main()
{
    int change;
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int coins = 0;

    do
    {
        change = get_int("change owed: ");
    }
    while (change < 0);

    if (change >= 25)
    {
        do
        {
            change = change - quarters;
            coins++;
        }
        while (change >= 25);
    }

    if (change >= 10)
    {
        do
        {
            change = change - dimes;
            coins++;
        }
        while (change >= 10);
    }

    if (change >= 5)
    {
        do
        {
            change = change - nickels;
            coins++;
        }
        while (change >= 5);
    }

    if (change >= 1)
    {
        do
        {
            change = change - pennies;
            coins++;
        }
        while (change >= 1);
    }

    printf("%d\n", coins);
}
