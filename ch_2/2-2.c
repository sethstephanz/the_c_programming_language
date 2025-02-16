#include <stdio.h>
#define LIMIT 100

// 2-2: Write a loop equivalent to the for loop above without using && or ||.
// for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
//      s[i] = c;

int main() {
    char buf[LIMIT] = {0};
    char c;
    int w = 0;

    for (int i = 0; i < LIMIT - 1; ++i) {
        if ((c = getchar()) != '\n') {
            if (c == EOF) {
                break;
            }
            buf[w] = c;
            w++;
        }
        else {
            break;
        }
    }

    printf("Line: %s", buf);
    return 0;
}

