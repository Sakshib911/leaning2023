/* Assume User will be providing input in the form of a string as show below. 
Write a function to parse the string and initialize an array of structures. 

Example String : "1001 Aron 100.00" 
Example Structure : 
    struct Student{
        int rollno;
        char name[20];
        float marks;
    };*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(char* input, struct Student* students, int numStudents) {
    char* token;
    int i = 0;

    // Parse the input string and initialize the structures
    token = strtok(input, " "); // Split the string by spaces

    while (token != NULL && i < numStudents) {
        students[i].rollno = atoi(token); // Convert rollno from string to int
        token = strtok(NULL, " ");

        strcpy(students[i].name, token); // Copy name
        token = strtok(NULL, " ");

        students[i].marks = atof(token); // Convert marks from string to float
        token = strtok(NULL, " ");

        i++;
    }
}

int main() {
    char input[] = "1001 Aron 100.00";

    // Count the number of spaces in the input string to determine the number of students
    int numSpaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            numSpaces++;
        }
    }

    int numStudents = numSpaces / 2 + 1; // Assuming the input is always valid

    // Dynamically allocate memory for the array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Initialize the students array by parsing the input string
    initializeStudents(input, students, numStudents);

    // Print the initialized student details
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
