#include <stdio.h>

// 1-2: More experimentation. What happens if you include \c in printf?

// gcc throws warning about '\c', but ultimately compiles and prints 'c' alongside
// other strings. '\\c' does not generate gcc error, and program prints '\c'.

main()
{
    printf("hello, world \c \n");
    printf("hello, world \\c \n");
}