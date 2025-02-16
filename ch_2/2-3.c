#include <stdio.h>
#include <ctype.h>
#define LIMIT 100
#define ERROR -1

// 2-3: Write the function htoi(s), which converts a string of hexadecimal digits
// (including optional 0x or 0X) into its equivalent integer values.

// The allowable digits are 0 through 9, a through f, and A through F.
// hex digits->int

int htoi(char s[]);

int main()
{
    // get string first
    char buf[LIMIT] = {0};
    char c;
    int w = 0;
    while ((c = getchar()) != '\n' && c != EOF && w < LIMIT - 1)
    {
        buf[w] = c;
        w++;
    }
    buf[w] = '\0'; // Buffer is already null-terminated, but good practice

    // call htoi
    int digit = htoi(buf);
    if (digit == ERROR)
    {
        return -1;
    }
    printf("%d\n", digit);
    return 0;
}

int htoi(char hex[])
{
    int result = 0;
    int r = 0; // read at index

    // skip optional 0x/0X (this only occurs at beginning of string)
    if (hex[r] == '0' && hex[r] == 'X' || hex[r] == 'x')
    {
        r = r + 2;
    }

    while (hex[r] != 0)
    {
        int value = 0;

        if (isdigit(hex[r]))
        {
            value = hex[r] - '0';
        }
        else if (hex[r] >= 'a' && hex[r] <= 'f')
        {
            value = hex[r] - 'a' + 10;
        }
        else if (hex[r] >= 'A' && hex[r] <= 'F')
        {
            value = hex[r] - 'A' + 10;
        }
        else
        {
            printf("Error: Invalid character!\n");
            return ERROR;
        }
        result = result * 16 + value;
        r++;
    }
    return result;
}
