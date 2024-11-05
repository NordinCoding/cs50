#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main()
{
    // array with letters
    int sum1 = 0;
    int sum2 = 0;

    string letters = {"abcdefghijklmnopqrstuvwxyz"};

    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    for (int i = 0; i < strlen(player1); i++)
    {
        if (player1[i] >= 'A' && player1[i] <= 'Z')
        {
            player1[i] = player1[i] + 32;
        }
    }

    for (int i = 0; i < strlen(player2); i++)
    {
        if (player2[i] >= 'A' && player2[i] <= 'Z')
        {
            player2[i] = player2[i] + 32;
        }
    }

    for (int i = 0; i < strlen(player1); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (letters[j] == player1[i])
            {
                sum1 += values[j];
            }
        }
    }

    for (int i = 0; i < strlen(player2); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (letters[j] == player2[i])
            {
                sum2 += values[j];
            }
        }
    }

    if (sum1 == sum2)
    {
        printf("Tie!\n");
    }
    else if (sum1 > sum2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}
