// In a two's compliment number system, x &= (x - 1) deletes the righmost 1-bit in x. Why?

/*
Decompose the statement x &= (x - 1):
1. Because of the nature of binary arithmetic, x - 1 will isolate the rightmost 0 bit:
E.g.:
x =       000111001100100
        - 000000000000001
        = 000111001100011

[Manual binary subtraction refresher: If there's a 0 in the principal,
you borrow from the nearest left 1, making the 0 a "11", then sub the 1 from that]

2. Then, x and (x - 1) are &ed together:
    000111001100100     x
&   000111001100011     x - 1
=   000111001100000     <- two &ed together. rightmost 1 bit from x has been deleted
*/

// Use answer to optimize bitcount function.
// Can substitute in x &= (x - 1) in loop head and can avoid check.
// We got from having to shift the number and then check every time to being
// able to count 1s more or less directly (we're counting each time we delete the rightmost one).
int bitcount(unsigned x) {
    int count;
    for (count = 0; x != 0; x &= (x - 1)) {
        count++;
    }
    return count;
}