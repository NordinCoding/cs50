#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char * password;
    do
    {
        password = get_string("Please enter a password: \n");
    }
    while (strlen(password) < 5);
    printf("%s\n", password);
}