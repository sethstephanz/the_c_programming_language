#include <stdio.h>

// 1-4: Write program that converts Celsius to Fahrenheit and prints table.

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limit of temp table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    celsius = lower;
    printf("Celsius\t Fahr.\n");
    while (celsius <= upper)
    {
        fahr = (celsius * (9.0 / 5.0)) + 32;
        printf("%6.1f\t %3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}