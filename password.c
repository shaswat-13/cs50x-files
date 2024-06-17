// a program to check if the given password has at least one lowercase letter, uppercase letter, number and symbol

// header files
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// prototype
bool valid(string password);

// main
int main(void)
{
    // prompting the user for a password
    string password = get_string("Enter your password: ");

    // printing the validity of password based on the functions return value
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    // initializing the condition variables as 0
    int uppr = 0, lwr = 0, num = 0, smbl = 0;

    // loop to iterate through each character in the password one by one
    for (int i = 0, pwd_len = strlen(password); i < pwd_len; i++)
    {
        // taking a single character
        char lttr = password[i];

        // checking if the character is in uppercase
        if (isupper(lttr))
        {
            uppr++;
        }

        // checking if the character is in lowercase
        else if (islower(lttr))
        {
            lwr++;
        }

        // checking if the character is a number (ASCII of 0-9 is 48-57)
        else if (lttr >= 48 && lttr <= 57)
        {
            num++;
        }

        // checking if the character is one of the symbols
        else if (lttr == '$' || lttr == '!' || lttr == '#')
        {
            smbl++;
        }
    }

    // returning true only if all the conditions are matched
    if (uppr > 0 && lwr > 0 && num > 0 && smbl > 0)
    {
        return true;
    }
    // else returning false
    else
    {
        return false;
    }
}
