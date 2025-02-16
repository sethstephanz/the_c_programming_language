#include <stdio.h>
#include <ctype.h>

// Write a program to print a histogram of the lengths of words in its input.
// Draw it horizontally. Challenge: Draw histogram vertically.

int main()
{
    int c = 0;
    int space_just_printed = 0;

    while ((c = getchar()) != EOF)
    {
        if (isspace(c))
        {
            if (!space_just_printed)
            {
                space_just_printed = 1;
                putchar('\n');
            }
        }
        else
        {
            space_just_printed = 0;
            putchar('#');
        }
    }
    return 0;
}
