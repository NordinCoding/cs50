#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long VISA;
    do
    {
        VISA = get_long("What is your VISA number? ");
        printf("%ld\n", VISA);
    }
    while(VISA < 0);
}



int credit(VISA)
{
    for(i = 0; i < 3; i++)
}