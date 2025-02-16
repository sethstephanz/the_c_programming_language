#include <stdio.h>
#include <ctype.h>
#define MAXLINE 100

// 1-18: For each line, delete trailing blanks and tabs. If line is blank, delete entirely.

int main()
{
    int c = 0;
    int char_present = 0; // check when we hit newline to make sure there was at least one char present in line
    char buf[MAXLINE] = {0};
    char out[MAXLINE] = {0};
    int w = 0; // write to buffer pointer
    int r = 0; // read from buffer pointer
    int t = 0; // transfer from buf to out (second write pointer)

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            if (char_present)
            {
                // start from end of buf[]. from end, if char is tab or space, skip.
                // then copy the rest of it to out[]. then, print out
                // start from end of buf[]
                t = r = w - 1;
                int trailing = 1;
                while (r >= 0)
                {
                    // if char is trailing tab or space, skip. otherwise, copy to out[]
                    if (!(isspace(buf[r])))
                    {
                        trailing = 0;
                        out[t] = buf[r];
                    }
                    else
                    {
                        if (!(trailing))
                        {
                            out[t] = buf[r];
                        }
                    }
                    t--;
                    r--;
                }
                r = 0;
                // now, print out out[]
                while (r < w)
                {
                    putchar(buf[r]);
                    r++;
                }

                putchar('\n');
            }
            // else, do nothing and go to newline routine
            // at start of new line
            char_present = 0;
            w = 0;
            r = 0;
            continue;
        }
        if (!(isspace(c)))
        {
            char_present = 1;
        }
        buf[w] = c;
        w++;
    }
    return 0;
}
