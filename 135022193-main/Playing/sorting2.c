#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    int unsorted[] = {7, 2, 5, 4, 1, 6, 0, 3};
    int len = sizeof(unsorted) / sizeof(unsorted[0]);
    int sorted[len];
    int tmp;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (unsorted[j] > unsorted[j+1])
            {
                tmp = unsorted[j];
                unsorted[j] = unsorted[j+1];
                unsorted[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < len; i++)
        {
            printf("%i ", unsorted[i]);
        }
    printf("\n");
}
