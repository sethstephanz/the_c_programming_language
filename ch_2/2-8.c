#include <stdint.h>
#include <stdio.h>
#define INT_SIZE 32

// 2-8: Rotate an integer by n bit positions.

int right_rotate(int x, int n) {
    // 1. Perform a right shift of n amount. This gets us the first part.
    // 2. In order to get the lost bits, we perform a complementary left shift
    // and return the two shifts OR'd together, which should give us the wrapped number.

    n %= INT_SIZE;                           // assuming 32-bit, but prevent undefined behavior
    return (x >> n) | (x << (INT_SIZE - n)); // OR right shift and complementary left shift together
}

void print_binary(uint32_t num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    uint32_t my_num = 1234567890;
    uint32_t n = 0;

    printf("Num before rotation:\t");
    print_binary(my_num);

    // perform all rotations. last number should match original
    for (int n = 1; n <= sizeof(my_num) * 8; n++) {
        int rotated = right_rotate(my_num, n);
        printf("Num after rotation:\t");
        print_binary(rotated);
    }

    return 0;
}