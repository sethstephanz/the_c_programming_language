#include <stdio.h>

// 1-15: Rewrite the temperature conversion program to use a function for conversion.

int convert(float fahr, int upper, int step);

int main()
{
    float fahr, celsius;
    int lower, upper, step;
    int conversion;

    lower = 0;   /* lower limit of temp table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    fahr = lower;
    printf("Fahr.\t Celsius\n");

    convert(fahr, upper, step);
    return 0;
}

int convert(float fahr, int upper, int step)
{
    float celsius;
    int conversion = 0;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}