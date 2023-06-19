/*1. Write a function to find biggest of 2 numbers using 
    - if else
 */
#include <stdio.h>

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    if (num1 > num2) {
        printf("The biggest number is: %d\n", num1);
    } else {
        printf("The biggest number is: %d\n", num2);
    }
    
    return 0;
}

