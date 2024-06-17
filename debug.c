// Become familiar wih C syntax
// Learn to debug buggy code

#include <cs50.h>

// need to include standardio header file to get the printf function
#include <stdio.h>

int main(void)
{
    // Ask for your name and where live

    // need to specify datatypes for name and location i.e. string
    // always need to put ; after each statement that needs to be executed
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    // Say hello

    // printf not print
    // since the name and location are string values the formatting in the printf should be %s not %i
    // \n to shift the $ sign to new line
    printf("Hello, %s, from %s! \n", name, location);
}
