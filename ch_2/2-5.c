#include <stdio.h>
#include <stdbool.h>
#define LIMIT 100

// 2-5: Write a function, any(s1, s2), that returns the first location
// in string s1 where any char from s2 appears. Return -1 if none appears.

int any(const char *s1, const char *s2);

int main() {
    char s1[LIMIT] = {0};
    char s2[LIMIT] = {0};

    printf("Please enter your first string: ");
    if (fgets(s1, LIMIT, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("Please enter your second string: ");
    if (fgets(s2, LIMIT, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    int res = any(s1, s2);
    if (res != -1) {
        printf("First matching character at index: %d\n", res);
    } else {
        printf("No matching characters found.\n");
    } 

    return 0;
}

int any(const char *s1, const char *s2) {
    bool char_found[256] = { false };
    
    while (*s2 && *s2 != '\n') {
        char_found[(unsigned char)*s2++] = true;
    }

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '\n') continue;
        if (char_found[(unsigned char)s1[i]]) {
            return i;
        }
    }
    return -1;
}

