#include <stdio.h>
#define MAXLINE 100

// 1-20: Replace tabs in the input with correct number of blanks.
// to space to the next tab stop. It replaces each tab with four spaces.

// int spaces_to_next_char(char buf[], int buf_ptr);

int main()
{
    int c = 0;
    while ((c = getchar()) != EOF)
    {
        // basically getline(). copies everything to each \n to buf
        char buf[MAXLINE] = {0};
        int w = 0;
        int r = 0;
        while (c != '\n')
        {
            if (c == '\t')
            {
                for (int i = 0; i < 4; i++)
                {
                    buf[w] = '#';
                    w++;
                }
            }
            else
            {
                buf[w] = c;
                w++;
            }
            c = getchar();
        }

        // print the line
        while (r < w)
        {
            putchar(buf[r]);
            r++;
        }
        if (buf[r] != '\n')
        {
            putchar('\n');
        }
    }
    return 0;
}
