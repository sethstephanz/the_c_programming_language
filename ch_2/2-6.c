#include <stdio.h>

// 2-6: Write a function, setbits(x, p, n, y), that returns x
// with the n bits that begin at position p set to the rightmost n bits
// of y, leaving the other bits unchanged.

int setbits(int x, int p, int n, int y);

int main() {
    // x: Original integer whose bits will be modified
    // p: Position (0-indexed from right) in x where you want to start changing bits
    // n: Number of bits to set starting from p
    // y: Integer whose rightmost n bits will be used to set the bits in x

    int x, p, n, y;
    int res;


    res = setbits(x, p, n, y);
    return 0;
}

int setbits(int x, int p, int n, int y) {
    // return x with n bits, which begin at position p, set to rightmost n bits of y, leaving
    // other bits unchanged
    
    // 1. get rightmost n bits of y
    int y_bits = y & ((1 << n) - 1);

    // 2. locate position p
    int mask = ~(((1 << n) - 1) << (p + 1 - n));
    x = x & mask;

    // 3. Shift the n bits of y into position p and combine with x.
    x = x | (y_bits << (p + 1 - n)); 
}
