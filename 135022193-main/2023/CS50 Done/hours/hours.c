#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    //delcaring the variables at floats
    float total = 0;
    float average;

    // loop for making a sum of all the hours given by user
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    // if statement for calculating and returning the average if user inputs 'A'
    if (output == 'A')
    {
        average = total / weeks;
        return average;
    }
    // else statement for returning the total if user inputs 'T'
    else
    {
        return total;
    }

}