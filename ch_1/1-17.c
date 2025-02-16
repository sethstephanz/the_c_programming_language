#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000

// 1-17: Print input lines that are longer than 80 chars.

int main()
{
    char buf[MAXLINE];
    int c = 0;
    int i = 0;
    int b = 0;
    while ((c = getchar()) != EOF)
    {
        buf[b] = c;
        b++;
        if (c == '\n')
        {
            // if char count is greater than 80, print buffer then clear
            // else, just clear it
            if (b > 80)
            {
                for (int i = 0; i < b; i++)
                {
                    putchar(buf[i]);
                }
            }
            else
            {
                printf("Short line skipped!\n");
            }
            b = 0;
            i = 0;
        }
    }
    return 0;
}