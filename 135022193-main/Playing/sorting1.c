#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int unsorted[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int len = sizeof(unsorted) / sizeof(unsorted[0]);
    int sorted[len];
    int min = len;

    for (int i = 0; i < len; i++)
    {
        min = len;
        for (int j = 0; j < len; j++)
        {
            if (unsorted[j] < min)
            {
                min = unsorted[j];
            }
        }
        for (int k = 0; k < len; k++)
        {
            if (unsorted[k] == min)
            {
                unsorted[k] = len;
            }
        }
        sorted[i] = min;

    }

    for (int i = 0; i < len; i++)
        {
            printf("%i ", sorted[i]);
        }
    printf("\n");
}
