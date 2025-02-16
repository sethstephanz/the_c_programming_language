#include <stdio.h>

// 1-8: Write a program that counts spaces, tabs, and newlines.

int main()
{
    int c = 0;
    int counter = 0;

    while ((c = getchar()) != EOF)
    {
        c = getchar();
        if (c == ' ' || c == '\n' || c == '\t')
        {
            counter++;
        }
    }
    printf("Amount of spaces, tabs, and newlines: %d\n", counter);
    return 0;
}