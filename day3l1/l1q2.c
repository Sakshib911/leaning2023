/*2. Prints Bits:
Scan a 32bit integer and prints its bits.

Concepts to be used.
- Loops
- Bitwise Operators*/

#include <stdio.h>

void printBits(unsigned int num) {
    int i;
    unsigned int mask = 1U << 31; // Start with the leftmost bit

    for (i = 0; i < 32; i++) {
        unsigned int bit = (num & mask) ? 1 : 0;
        printf("%d ", bit);
        
        mask >>= 1; // Shift the mask to the right by 1 bit
    }
    printf("\n");
}

int main() {
    unsigned int num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    printf("Bits: ");
    printBits(num);

    return 0;
}
