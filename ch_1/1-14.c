#include <stdio.h>
#include <ctype.h>

// 1-14: Write a program to print a histogram of the frequencies of different characters in its output.
// 1. Count frequencies of chars. 2. Print histogram of frequencies.
// e.g.:
// abbccc:
// a: #
// b: ##
// c: ###

int main()
{
    int alphabet_arr[26] = {0};
    int c = 0;

    while ((c = getchar()) != EOF)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            alphabet_arr[c - 'a']++;
        }
    }

    // for char in alphabet_arr:
    //      set i to number. while i > 0: print #. Then, print newline
    for (int i = 0; i < 26; i++)
    {
        int j = alphabet_arr[i];

        printf("%c: ", 'a' + i);

        while (j > 0)
        {
            putchar('#');
            j--;
        }
        putchar('\n');
    }

    return 0;
}