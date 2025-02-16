#include <stdio.h>

// 1-3: Modify conversion program provided and print a heading above the table.

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limit of temp table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    fahr = lower;
    printf("Fahr.\t Celsius\n");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}