/*
4. Write a function to find the type of the character passed
    - 'A' to 'Z', return 1
    - 'a; to 'z', return 2
    - '0' to '9', return 3
    - Any Other printable symbols, return 4
    - Non printable symbols, return 5 


 */
#include <stdio.h>
#include <ctype.h>

int find_char_type(char character) {
    if (isalpha(character)) {
        if (isupper(character)) {
            return 1; // Uppercase letter
        } else {
            return 2; // Lowercase letter
        }
    } else if (isdigit(character)) {
        return 3; // Digit
    } else if (isprint(character)) {
        return 4; // Printable symbol
    } else {
        return 5; // Non-printable symbol
    }
}

int main() {
    char character;
    
    printf("Enter a character: ");
    scanf(" %c", &character);
    
    int result = find_char_type(character);
    
    switch (result) {
        case 1:
            printf("Type: Uppercase letter\n");
            break;
        case 2:
