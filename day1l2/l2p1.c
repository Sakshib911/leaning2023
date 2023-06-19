/*
3. Write a function to find if a give character is vowel using switch case statements, 
    - If vowel, return 1
    - If not vowel, return 0;

In main print,
"Vowel" if return value is 1
"Not Vowel" if return value is 1
*/
#include <stdio.h>

int is_vowel(char character) {
    switch (character) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return 1; // Vowel
        default:
            return 0; // Not a vowel
    }
}

int main() {
    char character;
    
    printf("Enter a character: ");
    scanf(" %c", &character);
    
    int result = is_vowel(character);
    
    if (result == 1) {
        printf("Vowel\n");
    } else {
        printf("Not Vowel\n");
    }
    
    return 0;
}
