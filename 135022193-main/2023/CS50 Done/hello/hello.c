#include <stdio.h>
#include <cs50.h>

int main(void)
// function prompts user for name and prints a sentence saying hello to them.
{
    string name = get_string("Whats your name?\n ");
    printf("hello, %s\n", name);
}