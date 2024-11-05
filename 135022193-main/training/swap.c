#include <stdio.h>

int swap(int *x, int *y);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x: %d\ny: %d\n", x, y);

    swap(&x, &y);

    printf("x: %d\ny: %d\n", x, y);
}

int swap(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;

    return 0;
}
