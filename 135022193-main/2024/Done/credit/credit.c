#include <cs50.h>
#include <stdio.h>

int main()
{
    int check;
    int digit;
    int split;
    int sum;
    int sum1 = 0;
    int sum2 = 0;
    int i = 0;
    long amex;
    long master;

    long card = get_long("Number: ");
    long visa = card;
    long copyCard = card;

    while (card != 0)
    {
        digit = card % 10;
        if (i % 2 == 0)
        {
            sum1 += digit;
        }
        else
        {
            digit = digit * 2;
            if (digit >= 10)
            {
                while (digit != 0)
                {
                    split = digit % 10;
                    sum2 += split;
                    digit /= 10;
                }
            }
            sum2 += digit;
        }
        card /= 10;
        i++;
    }
    sum = sum1 + sum2;
    check = sum % 10;
    if (check == 0)
    {
        while (visa >= 10)
            {
                visa /= 10;
            }
            if ((visa == 4 && i == 13) || (visa == 4 && i == 16))
            {
                printf("VISA\n");
            }
        else if (i == 15)
        {
            amex = copyCard;
            while (amex >= 100)
            {
                amex /= 10;
            }
            if (amex == 34 || amex == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (i == 16)
        {
            master = copyCard;
            while (master >= 100)
            {
                master /= 10;
            }
            if (master > 50 && master < 56)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
