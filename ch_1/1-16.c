#include <stdio.h>
#define MAXLINE 1000

// 1-16: Revise the main routine of the longest-line program so it will correctly print
// the length of arbitrarily long input lines, and as much as possible of the text.

// The point of this exercise is to handle buffer overflow safely and without using dynamic
// memory allocation. So, no malloc(), calloc(), etc.
// Basically, you need to track the TOTAL amount of lines (over and above MAXLINE), then
// draw from that counter to continue to allocate static arrays of size TOTAL - MAXLINE.

int getaline(char line[], int maxline); // call this 'getaline', otherwise will conflict with getline()
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;               // current line length
    int max;               // max length seen so far
    char line[MAXLINE];    // current input line
    char longest[MAXLINE]; // longest line saved here

    max = 0;
    while ((len = getaline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) // there was a line
    {
        printf("%s", longest);
    }
    return 0;
}

/* getaline: read a line into s, return length of the line */
int getaline(char s[], int lim)
{
    int c, i, j; // j will keep track of absolute length of line
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}
