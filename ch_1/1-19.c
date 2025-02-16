#include <stdio.h>
#define MAXLINE 1000

// 1-19: Reverse a string.
// Reverse input one line at a time.
// This only does one line and then stops, but this is the general idea.

void reverse(char s[], int w);

int main()
{
    int w, c = 0;
    char buf[MAXLINE] = {0};
    while ((c = getchar()) != EOF)
    {
        while ((c != '\n') && (w < MAXLINE))
        {
            buf[w] = c;
            w++;
            c = getchar();
        }
        reverse(buf, w);
        w = 0; // restart buffer write counter
    }
    return 0;
}

void reverse(char s[], int s_read)
{
    char out[MAXLINE] = {0};
    int w = 0;
    int s_len = s_read;
    while (s_read >= 0)
    {
        out[w] = s[s_read];
        s_read--;
        w++;
    }
    while (s_read <= s_len)
    {
        putchar(out[s_read]);
        s_read++;
    }
    putchar('\n');
}
