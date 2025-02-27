#include <ctype.h>
#include <stdio.h>

// Write a function that converts uppercase letters to lowercase. Use a ternary operator.

void to_lower(char *string) {
    // getchar until newline
    // if not alpha:     do nothing
    // elif:             if it is not uppercase, do nothing
    // else:             convert to lowercase

    // loop thru string. while char not null
    //      if not alpha ? not uppercase : convert to lowercase

    for (int i = 0; string[i] != '\0'; i++) {
        // condition ? if_true : if_false;
        // note that condition has to be something that assesses to true or false
        // it is the same as: if (condition) ? do this : else, do this

        // if the char is a letter and is uppercase ? convert to lower : don't do anything
        (isalpha(string[i]) && isupper(string[i])) ? string[i] = tolower(string[i]) : 0;
    }
}

int main() {
    char my_string[] = "123 abc ABC. $Aa^&Bb&*Cc*. Hello, World!!!\t\t\t\n";
    printf("Before: %s\n", my_string);
    to_lower(my_string);
    printf("After: %s\n", my_string);

    return 0;
}
