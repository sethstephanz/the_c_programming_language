#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Write a function that expands list shorthand into full lists.
    For instance, 'a-z' gets expanded into abcd...xyz (full list),
        '1-100' gets expanded into 123...99100.

    Handle edge cases like:
        'a-b-z' and '-a-z' (in this case, the '-' would be printed before the expanded list)
        'a-b-z' -> is equivalent to a-b + c-z
        '-a-z' -> ignore first '-'
        'a-z-' -> ignore last '-'
        'a--z' -> invalid. ignore whole thing
        'a-b-y-a' -> expand a-b. expand c-y. ignore -a if at end, or treat as new start.
*/

char *list_expand(char start, char end) {
    // working with character version of numeral, so can just treat them
    // the same way as alpha chars
    int list_size = end - start + 1; // +1 for null terminator
    char *new_list = malloc(list_size);

    char my_char = start;
    for (int i = 0; i < list_size; i++) {
        new_list[i] = my_char++;
    }
    new_list[26] = '\0';
    return new_list;
}

int main() {
    /*
        Loop through list.
        If valid arg found, which has to be of form '
    */
    char alpha_start = '\0';
    char alpha_end = '\0';
    char num_start = '\0';
    char num_end = '\0';

    char my_string[] = "a-b-z1-9";
    // char my_string[] = "-a-b-z-1-9-";

    for (int i = 0; i < strlen(my_string); i++) {
        printf("%c\n", my_string[i]);
        if (isalpha(my_string[i]) && !alpha_start) {
            alpha_start = my_string[i];
        } else if ((isalpha(my_string[i])) && (alpha_start) && (i > 0) && (my_string[i - 1] == '-') && ((i + 1) > sizeof(my_string) || !isalpha(my_string[i + 1]))) {
            alpha_end = my_string[i];
            char *my_list = list_expand(alpha_start, alpha_end);
            alpha_start = '\0';
            alpha_end = '\0';
            printf("%s\n", my_list);
            free(my_list);
        } else if (isdigit(my_string[i]) && !num_start) {
            num_start = my_string[i];
        } else if (isdigit(my_string[i]) && num_start != '\0' && i > 0 && my_string[i - 1] == '-' && ((i + 1) > sizeof(my_string) || !isalpha(my_string[i + 1]))) {
            num_end = my_string[i];
            char *my_list = list_expand(num_start, num_end);
            num_start = '\0';
            num_end = '\0';
            printf("%s\n", my_list);
            free(my_list);
        } else if (!num_start && !alpha_start) {
            printf("%c", my_string[i]);
        }
    }
    printf("\n");
    return 0;
}
