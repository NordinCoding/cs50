// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}


int max(int array[], int n)
{
    int max;
    int max_pos;
    for (int i = 0; i < n; i++)
    {
        max_pos = 1;
        for (int j = i; j < n; j++)
        {
            if (array[j] > array[max_pos])
            {
                max_pos = j;
                max = array[j];
            }
        }
    }
    printf("%i\n", max);
    return 0;
}
