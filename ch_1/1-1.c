#include <stdio.h>

// 1-1: Print "hello, world!"

int print_hw();

int main()
{
    printf("hello, world!");
    return print_hw();
}

int print_hw()
{
    printf("hello, world!\n");
    return 0;
}