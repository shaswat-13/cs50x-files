// a program to print minimum number of coins to give for changes owed
// coins are 25,10,5,1 cents

#include <cs50.h>
#include <stdio.h>

// calling all the declared functions
int get_change();
void print_coins(int change);

// main body
int main(void)
{

    // takes the input of change from the user
    int change = get_change();

    // takes in changes as input and displays the no of coins as output(side effect)
    print_coins(change);
}

// function that takes the positive non decimal value for change
int get_change()
{
    int p;
    do
    {
        p = get_int("Change owed: ");
    }
    while (p < 0);

    return p;
}

// function that prints out number of coins
void print_coins(change)
{
    // declaring coins as a local variable
    int coins = 0;

    // this program could be made better by also displaying number of 25,10,5,1 cent coins and finally the total
    // it could be done by declaring localvariables as qrtr, dime, nckl, pnny and increasing their value by 1 instead of the coins
    // also there must be a way to nest the loops with the use of arrays or sth

    // this loop counts the number of quarters
    while (change >= 25)
    {
        coins++;
        change = change - 25;
    }

    // this loop counts the number of dimes
    while (change >= 10)
    {
        coins++;
        change = change - 10;
    }

    // this loop counts the number of nickels
    while (change >= 5)
    {
        coins++;
        change = change - 5;
    }

    // this loop counts the number of pennies
    while (change != 0)
    {
        coins++;
        change = change - 1;
    }

    // finally prints the total number of coins
    printf("%i \n", coins);
}
