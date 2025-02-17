#include <stdint.h>
#include <stdio.h>

// 2-7: Write a function that returns an integer, x, with bits in range n thru n
// + p (inclusive) inverted (assuming n < p) leaving other bits unchanged.

int invert(uint32_t x, uint32_t p, uint32_t n) {
    uint32_t mask = ((1U << (p - n + 1)) - 1) << n; // create mask for range n thru p (r to l, inclusive)
    return x ^ mask;                                // XOR to flip bits in range
}

void print_binary(uint32_t num, uint32_t p, uint32_t n) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        if (i <= p && i >= n) {
            // print the inverted bits in green to assess output visually
            printf("\033[32m%d\033[0m", (num >> i) & 1);
        } else {
            printf("%d", (num >> i) & 1);
        }
    }
    printf("\n");
}

int main() {
    uint32_t x = 0b1100101010101110001110101010;

    // this one does bits 5 thru 10 (from right) inclusive. so 6 bits total should be inverted
    int p = 10;
    int n = 5;

    uint32_t result = invert(x, p, n);

    printf("Original:\t");
    print_binary(x, p, n);
    printf("Modified:\t");
    print_binary(result, p, n);

    return 0;
}