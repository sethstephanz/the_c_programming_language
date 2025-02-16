#include <stdio.h>

// 1-12: Write a program that prints input one word per line.

int main()
{
    int just_printed_NL = 0;
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        if (isspace(c))
        {
            if (just_printed_NL)
            {
                continue;
            }
            else
            {
                just_printed_NL = 1;
                putchar('\n');
            }
        }
        else
        {
            putchar(c);
            just_printed_NL = 0;
        }
    }
    putchar('\n');
    return 0;
}
