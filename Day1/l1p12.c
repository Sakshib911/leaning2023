/*1. Write a function to find biggest of 2 numbers using 
    - ternary operator
 */
#include <stdio.h>

int main() {
    int num1, num2;
    
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int result = (num1 > num2) ? num1 : num2;
    printf("The biggest number is: %d\n", result);
    
    return 0;
}
