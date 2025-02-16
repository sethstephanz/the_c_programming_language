#include <stdio.h>
#include <limits.h>
#define DIVIDER_LENGTH 40

// 2-1: Determine the ranges of char, short, int, and long variables, both signed and unsigned, by
// printing appropriate values from standard headers and by direct computation.

// Expanding on this: Learning about limits.h, doing some bit shifting, learning about more data types, getting some more casting experience and doing some more multi-function stuff. Print signatures. Hit head against annoying casting rules.

void char_range();
void short_range();
void int_range();
void long_range();
void print_divider();

int main()
{
    char_range();
    short_range();
    int_range();
    long_range();
    return 0;
}

void char_range()
{
    print_divider();
    printf("CHAR RANGES\n");
    print_divider();
    printf("Printed from limits.h:\n");
    printf("Signed char range: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char range: 0 to %d\n", UCHAR_MAX);
    print_divider();
    printf("Calculated using bit manipulation:\n");
    // char is signed by default. so we get an unsigned char's amount of 0s, negate the 0s to 1s (you can just do 1s), then right shift it by 1 (to account for sign bit)
    // (remember that signed chars use the MSD to store signed vs. unsigned)
    printf("Signed char range: %d to %d\n", -(char)((unsigned char)~0 >> 1) - 1, (char)((unsigned char)~0 >> 1));
    printf("Unsigned char range: 0 to %u\n", (unsigned char)~0);
}
void short_range()
{
    print_divider();
    printf("SHORT RANGES\n");
    print_divider();
    printf("Printed from limits.h:\n");
    printf("Signed short range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short range: 0 to %d\n", USHRT_MAX);
    print_divider();
    printf("Calculated using bit manipulation:\n");
    printf("Signed short range: %hd to %hd\n", (short)(-(short)((unsigned short)~0 >> 1) - 1), (short)((unsigned short)~0 >> 1));
    printf("Unsigned short range: 0 to %hu\n", (short)((unsigned short)~0));
}
void int_range()
{
    print_divider();
    printf("INT RANGES\n");
    print_divider();
    printf("Printed from limits.h:\n");
    printf("Signed int range: %d to %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int range: 0 to %u\n", UINT_MAX);
    print_divider();
    printf("Calculated using bit manipulation:\n");
    printf("Signed int range: %d to %d\n", -(int)((unsigned int)~0 >> 1) - 1, (int)((unsigned int)~0 >> 1));
    printf("Unsigned int range: 0 to %u\n", (unsigned int)~0);
}
void long_range()
{
    print_divider();
    printf("LONG RANGES\n");
    print_divider();
    printf("Printed from limits.h:\n");
    printf("Signed long range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long range: 0 to %lu\n", ULONG_MAX);
    print_divider();
    printf("Calculated using bit manipulation:\n");
    printf("Signed long range: %ld to %ld\n", -(long)((unsigned long)~0 >> 1) - 1, (long)((unsigned long)~0 >> 1));
    printf("Unsigned long range: 0 to %lu\n", (unsigned long)~0);
}

void print_divider()
{
    for (int i = 0; i < DIVIDER_LENGTH; i++)
    {
        putchar('-');
    }
    putchar('\n');
}