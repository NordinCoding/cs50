#include <cs50.h>
#include <stdio.h>

void total(int, int);

int main(void)
{
    // TODO: Prompt for start size
    int start = 1000;
    printf("start size: %d\n", start);

    // TODO: Prompt for end size
    int end = 1500;
    printf("end size: %d\n", end);

    // TODO: Calculate number of years until we reach threshold and print the number of years
    {
        total(start, end);
    }

}







void total(start, end)
{
    int n;
    n = start / 3;

    int i;
    i = start / 4;

    int j;
    j = n - i;

    int years;
    years = (end - start) / j;
    printf("Years: %d\n", years);
}