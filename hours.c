// a program to print either sum or average of the hours spent in CS50 problem sets

// header files
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// prototype
float calc_hours(int hours[], int weeks, char output);

// main
int main(void)
{
    // getting the no of weeks from the user then initializing the array of hours of same number of elements
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    // getting the number of hours and keeping them in the array
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    // asking to calculate total or average hours
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // displaying the output by calling the function

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // loop to get the total number of hours
    int sum;
    for (int i = 0; i < weeks; i++)
    {
        sum = sum + hours[i];
    }

    // returning the total or average hours based on the users preference
    if (output == 'T')
    {
        float total = sum + 0.0;
        return (total);
    }
    else
    {
        float avg = (float) sum / (float) weeks;
        return (avg);
    }
}
