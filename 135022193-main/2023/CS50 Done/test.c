#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int x = 'b';
    printf("%i\n", (x = x - 97));

    int y = 'B';
    printf("%i\n", (y = y - 65));
}
