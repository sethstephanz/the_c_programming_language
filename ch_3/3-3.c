#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

/*
    Write a function that expands list shorthand into full lists.
    For instance, 'a-z' gets expanded into abcd...xyz (full list),
        '1-100' gets expanded into 123...99100.

    Each valid expansion has to be of the form 'x-y', where x < y. Otherwise, print it literally.
        So, process greedily. If start not set and hit a number or letters, look forward one.
        If i+1 is not '-', print i and i+1 literally and increment i twice
        If i = start and i+1 = '-' and i+2 equals something of the same order, and i < i+2, expand and increment
        i by two. Really trying to not use a stack here!

    Handle edge cases like:
        'a-b-z' and '-a-z' (in this case, the '-' would be printed before the expanded list)
        'a-b-z' -> is equivalent to a-b + c-z
        '-a-z' -> ignore first '-'
        'a-z-' -> ignore last '-'
        'a--z' -> invalid. ignore whole thing
        'a-b-y-a' -> expand a-b. expand c-y. ignore -a if at end, or treat as new start.
*/

void expand(char start, char end) {
    while (start <= end) {
        printf("%c", start++);
    }
    printf("\n");
    return;
}

int main() {
    char my_string[] = "-a-b-za--z-1-9-";
    char start = '\0';
    char end = '\0';

    int alpha = False;   // alphabetical sequence was just printed
    int numeric = False; // numeric sequence was just printed

    for (int i = 0; i < sizeof(my_string); i++) {
        if (isalpha(my_string[i])) {
            if (!start || isnumber(start)) {
                start = my_string[i];
            } else if (!end) {
                // if it's a continuance of kind, skip the last number printed
                if (alpha) {
                    if (start < my_string[i])
                        start++;
                    else {
                        // invalid. print vals literally, reset start and end and reset
                        printf("%c", my_string[i]);
                        start = '\0';
                        end = '\0';
                        continue;
                    }
                }

                end = my_string[i];
                expand(start, end);
                start = end;
                end = '\0';
                alpha = True;
                numeric = False;
            }
        } else if (isnumber(my_string[i])) {
            if (!start || isalpha(start)) {
                start = my_string[i];
            } else if (!end) {
                if (numeric) {
                    if (start < my_string[i])
                        start++;
                    else {
                        printf("%c", my_string[i]);
                        start = '\0';
                        end = '\0';
                        continue;
                    }
                }
                end = my_string[i];
                expand(start, end);
                numeric = True;
                start = end;
                end = '\0';
                numeric = True;
                alpha = False;
            }
        } else {
            if (!start) {
                printf("%c\n", my_string[i]);
            }
        }
    }

    return 0;
}
