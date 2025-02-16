#include <stdio.h>

// 1-10: Write a program to copy input to output, replacing each tab, backspace, and backslash with
// their respective character literals.

int main()
{
    int c = 0;
    int counter = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t') // this is correct, just messed up on mac
        {
            printf("\\t");
            continue;
        }
        else if (c == '\b')
        {
            printf("\\b");
            continue;
        }
        else if (c == '\\')
        {
            printf("\\");
            continue;
        }
        putchar(c);
    }
    return 0;
}