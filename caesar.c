// a program to encrypt the plaintext by a key given by the user and display ciphertext

// header files
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main asks the key in the cli
int main(int argc, string argv[])
{
    // control statements that will end the program unless user has typed the cl-arguement in the
    // required format i.e. no more than input of a key and the key should be a +ve integer
    if (argc != 2)
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    for (int k = 0, len_argv = strlen(argv[1]); k < len_argv; k++)
    {
        if (!isdigit(argv[1][k]))
        {
            printf("Usage ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);

    // get the plaintext from the user
    string txt = get_string("Plaintext:  ");

    // displaying the ciphertext
    printf("Ciphertext: ");

    // reduces higher value of key to smaller one
    key = key % 26;

    // initializing a character of plaintext as lttr
    char lttr;

    // loop that checks for every letter of the plaintext one at a time
    for (int i = 0, len = strlen(txt); i < len; i++)
    {

        lttr = txt[i];

        // if the letter is uppercase, first converts A to 0 and Z to 26, adds the key
        // then prevents the value from exceeding Z by wrapping back to A by MOD 26
        // then converts into actual ascii value of the cipherletter and stores it in lttr
        if (isupper(lttr))
        {
            lttr = txt[i] + key - 'A';
            lttr = lttr % 26 + 'A';
        }

        // does the same process for lowercase letters
        else if (islower(lttr))
        {
            lttr = txt[i] + key - 'a';
            lttr = lttr % 26 + 'a';
        }

        // for non alphabetic value stores them as it is
        else
        {
            lttr = txt[i];
        }

        // displays the letter
        printf("%c", lttr);
    }

    // returns 0 to signify successful program
    printf("\n");
    return 0;
}
