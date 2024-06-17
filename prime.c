// a program to show all the prime numbers from a minimum to a maximum value given by the user
#include <cs50.h>
#include <math.h>
#include <stdio.h>

// a user defined function which takes input of a integer (call it number)
// performs its task and outputs or returns a boolean value (true:1 or false:0) to the main program
bool prime(int number);

int main(void)
{
    // asks the user minimum value until the user inputs a positive integer
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // asks the user maximum value until the user inputs a number greater or equal to the minimum value
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // loops from minimum to maximum value with a single increment each time to test if it is a prime number or not
    for (int i = min; i <= max; i++)
    {
        // prime() is a user defined function with a boolean return value that will check if the number is prime or not
        // if the return value is true then it prints else it doesnt and again goes to the top of the loop
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{

    // declaring roots as 0, if there is more than 1 root then the number is not prime it is composite
    int roots = 0;

    // since 1 is neither prime nor composite so this will make sure it doesnt display 1 as a prime number
    if (number == 1)
    {
        return 0;
    }

    // a loop that runs from 2 to the square root of that number to check if the number is perfectly divided or not
    // till square root because any number over the square root of certain number can never perfectly divide it (more efficient)
    // if any number before the square root divides it then the value of root increases

    for (int div = 2; div <= sqrt(number); div++)
    {
        float rem = number % div;
        if (rem == 0)
        {
            roots++;
        }
    }

    // checking if it has no roots i.e is a prime number or has roots i.e. composite number
    // if prime returns 1 else returns 0

    if (roots == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
