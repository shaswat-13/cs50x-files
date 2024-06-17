// a program to replace vowels in a word with numbers
// a -> 6, e -> 3, i -> 1, o -> 0, u -> no change

// header files
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// main
int main(int argc, string argv[])
{
    // loop for proper command line arguement
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    else
    {
        // loop to replace the vowels with the numbers
        for (int i = 0, word_len = strlen(argv[1]); i < word_len; i++)
        {
            char lttr = argv[1][i];

            if (lttr == 'a')
            {
                printf("6");
            }
            else if (lttr == 'e')
            {
                printf("3");
            }
            else if (lttr == 'i')
            {
                printf("1");
            }
            else if (lttr == 'o')
            {
                printf("0");
            }
            else
            {
                printf("%c", lttr);
            }
        }
        printf("\n");

        // ending the program with exit status 0 if everything runs smoothly
        return 0;
    }
}
