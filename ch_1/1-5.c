#include <stdio.h>

// 1-5: Modify conversion program to print table in reverse order (300 down to 0).
// Using for loop instead of while loop (section 1.3 is on for loops).
// Using constant declarations for important numbers.

#define LOWER 0   /*lower limit of table*/
#define UPPER 300 /*upper limit*/
#define STEP 20   /*step size*/

int main()
{
    float fahr, celsius;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t %6.1f\n", fahr, celsius);
    }
    return 0;
}