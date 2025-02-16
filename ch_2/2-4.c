#include <stdio.h>
#define LIMIT 100

// 2-4: Write an alternate version of squeeze(s1, s2) that deletes
// each character in s1 that matches any character in the string s2.

void squeeze(char *buf, char *buf2, char *squeezed);

int main()
{
    int c; // char
    int w; // write
    char buf[LIMIT] = {0};
    char buf2[LIMIT] = {0};
    char squeezed[LIMIT] = {0};

    printf("Please enter the string you'd like to delete chars from:\n");
    // Copy string we're deleting from to buffer 1
    w = 0;
    c = getchar();
    while (c != '\n' && w < LIMIT - 1 && c != EOF)
    {
        buf[w++] = c;
        c = getchar();
    }
    buf[w] = '\0';

    printf("Please enter the chars you'd like to delete from that string:\n");
    // Copy letters we're deleting from string 1 to buffer 2
    w = 0;
    c = getchar();
    while (c != '\n' && w < LIMIT - 1 && c != EOF)
    {
        buf2[w++] = c;
        c = getchar();
    }
    buf2[w] = '\0';

    // call squeezed
    squeeze(buf, buf2, squeezed);

    printf("Squeezed: %s\n", squeezed);
    return 0;
}

void squeeze(char *string, char *chars, char *squeezed)
{
    int w_squ = 0;
    int r_str = 0;

    while (string[r_str] != 0)
    {
        int r_cha = 0;
        while (chars[r_cha] != 0)
        {
            if (string[r_str] == chars[r_cha])
            {
                // if a char from string matches a char from chars,
                // break, skip char, and do not write to squeezed buffer
                break;
            }
            r_cha++;
        }
        // we got to end of chars without a break. append char
        if (chars[r_cha] == 0)
        {
            squeezed[w_squ] = string[r_str];
            w_squ++;
        }
        r_str++;
    }
    squeezed[w_squ] = 0;
}
