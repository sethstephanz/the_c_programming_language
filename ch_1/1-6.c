#include <stdio.h>

// 1-6: Verify that the expression getchar() != EOF is 0 or 1.
// A little unclear to me what this actually wants me to do, but I belive my program
// does what it asks very literally. Does the provided expression assess to 0 or 1?
// If so, print this message.

int main()
{
    int c;

    while (((c = getchar()) != EOF) == 1 || ((c = getchar()) != EOF) == 0)
    {
        printf("I am verifying\n");
    }
    return 0;
}