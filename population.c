// a program to calculate the years required for starting population to reach the ending population
// when there are n/3 births a year and n/4 deaths a year
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for starting population at least 9
    int sp;

    do
    {
        sp = get_int(" enter the starting population: ");
    }
    while (sp < 9);

    //ask for ending population greater than starting population
    int ep;

    do
    {
        ep = get_int(" enter the ending population: ");
    }
    while (ep < sp);

    //loop until start population equals or exceeds ending populaion and count the years
    int year = 0;
    int g;
    int l;

    if (ep == sp)
    {
        printf("Years: 0 \n");
    }

    else
    {
        do
        {
            g = sp / 3;
            l = sp / 4;
            sp = sp + g - l;
            year++;
        }
        while (sp < ep);

        //display the year count
        printf("Years: %i\n", year);
    }

}
