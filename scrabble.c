// a program to show who wins in a game of scrabble when two people put their respective words

// all the header files essential
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// prototypes of the user defined functions
int calc_score(string word, int points[]);

// main
int main(void)
{
    // getting two words from the user
    string word_1 = get_string("Player 1: ");
    string word_2 = get_string("Player 2: ");

    // array of scores of each letter
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // find out the scores of each words using a single function
    int pts_1 = calc_score(word_1, points);
    int pts_2 = calc_score(word_2, points);

    // function (how???? didnt run so kept at main function)
    // code that compares which user has more points and displays the winner
    if (pts_1 > pts_2)
    {
        printf("Player 1 wins!\n");
    }
    else if (pts_2 > pts_1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// function which first converts the word to character in uppercase,
// adds the points assigned to each letter and returns the score
// check isupper islower and then add scores and points 
int calc_score(string word, int points[])
{
    int pts = 0;

    for (int i = 0, word_len = strlen(word); i < word_len; i++)
    {
        // takes a single character from 'i'th position of the string and makes uppercase
        char letter = word[i];
        letter = toupper(letter);

        // finds out the position in array for respective points
        // beacause A = 65 in integer and therefore subtracting 65 to get the position of points from the array
        int position = (int) letter - 65;

        // adding the points
        pts = pts + points[position];
    }
    return pts;
}
