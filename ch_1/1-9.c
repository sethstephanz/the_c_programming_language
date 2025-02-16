#include <stdio.h>

// 1-9: Write a program to copy input to output.
// Trim excess space chars.

int main()
{
    int c = 0;
    int counter = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(' ');
            while (c == ' ' && c != EOF)
            {
                c = getchar();
            }
        }
        putchar(c);
    }
    return 0;
}