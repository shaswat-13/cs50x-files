// a program to find out the grade of the user based on the text input

// header files
// cs50 -> get_string() | ctype -> islower(), isupper() | math -> round() | stdio -> printf() | string -> strlen()
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototype
int find_lvl(string text);

// main
int main(void)
{
    // ask the user for the text
    string passage = get_string("Text: ");

    // feed it to the function
    int level = find_lvl(passage);

    // print the grade based on the result
    if (level < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (level >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", level);
    }
}

// a function that first dissects the number of letters, words and sentences then
// finds the grade with formula index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words in the text
// and S is the average number of sentences per 100 words in the text
int find_lvl(string text)
{
    int words = 0, lttrs = 0, sntcs = 0;

    // loop that checks the number of letters, words and strings
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        char check = text[i];

        if (check == ' ')
        {
            words++;
        }

        else if (check == '.' || check == '?' || check == '!')
        {
            sntcs++;
        }

        else if (isupper(check) || islower(check))
        {
            lttrs++;
        }
    }
    // because one space separates two words and the number of words is always 1 more than the space
    words = words + 1;

    // calculation and rounding up then returning the value
    float L = lttrs * 100.0 / words;
    float S = sntcs * 100.0 / words;
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(index);
    
    return grade;
}
