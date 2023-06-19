/*Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986

Concepts to be used.
- Loops
- Operators*/

#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);
    
    int largest = 0;
    int divisor = 1;
    
    while (divisor <= number) {
        int temp = (number / (divisor * 10)) * divisor + (number % divisor);
        if (temp > largest) {
            largest = temp;
        }
        divisor *= 10;
    }
    
    printf("Largest number after deleting a single digit: %d\n", largest);
    
    return 0;
}
