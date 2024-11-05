#include <stdio.h>

int main(void)
{
    int n;

    do
    {
        printf("give me a number: ");
        scanf("%d", &n);
    } while ((n > 8) || (n < 1));


    for(int i = 0; i < n; i++)
    {
        for(int j = (n - 1); j > i; j--)
        {
            printf(" ");
        }
        for(int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for(int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
