/* Write a program to sum every alternate elements of a given array starting for element 0
For example, let's say we have a[5] = {10, 20, 30, 40, 50}, the result should be 10 + 30 + 50 = 90

Topics to be covered
- Arrays
- Loops
- Basic Operators*/
#include <stdio.h>

int sum_alternate_elements(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i += 2) {
        result += arr[i];
    }
    return result;
}

int main() {
    int array[] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]);
    int total = sum_alternate_elements(array, size);
    printf("Sum of alternate elements: %d\n", total);
    return 0;
}
