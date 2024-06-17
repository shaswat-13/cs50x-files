// double pyramid mario with hole in the middle
#include <stdio.h>

int main(void)
{
    // getting the height from the user
    int n = 0;
    while (n > 8 || n < 1)
    {
        printf("Height: ");
        scanf("%i", &n);
    }

    // running the loop till height
    for (int i = 0; i < n; i++)
    {
        // for the beginning spaces
        for (int j = n - 1; j > i; j--)
        {
            printf(" ");
        }

        // for the left tiles
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // the central hole
        printf("  ");

        // for the right tiles
        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}
