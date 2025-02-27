#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Write a function that copies a string in one buffer to another buffer.
    While it does this, it should replace characters like tabs and newlines with their
    literal representations. Use a switch statement.
*/

char *copy_string(char *src) {
    // get special char count. this will tell us how large to make destination buffer
    // with most precision, least memory waste, and least memory overhead
    int offset = 0;
    int base = 0;
    int s = 0;
    while (src[s] != 0) {
        if (src[s] == '\n' || src[s] == '\b' || src[s] == '\t') {
            offset++;
        }
        base++;
        s++;
    }

    // allocate appropriate amount of space for new string
    int copy_size = base + offset;
    char *dst = malloc(copy_size);

    // char literal representations are two chars, so will have to take up two spaces to encode correctly
    int d = 0;
    for (s = 0; s < base; s++) {
        switch (src[s]) {
        case '\n':
            dst[d++] = '\\';
            dst[d] = 'n';
            break;
        case '\b':
            dst[d++] = '\\';
            dst[d] = 'b';
            break;
        case '\t':
            dst[d++] = '\\';
            dst[d] = 't';
            break;
        default:
            dst[d] = src[s];
            break;
        }
        d++;
    }
    return dst;
}

int main() {
    char my_string[] = "abc\tABC\t123\b123\nhello, world!\n";
    printf("Source: %s", my_string);

    char *dst = copy_string(my_string);
    printf("Copy: %s\n", dst);
    free(dst);
}
