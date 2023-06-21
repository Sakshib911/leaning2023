/* write a program to Store Data for n students in Structures Dynamically. */

#include <stdio.h>
#include <stdlib.h>

// Structure for representing a student
struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of 'n' student structures
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Read student data
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &(students[i].age));
        printf("GPA: ");
        scanf("%f", &(students[i].gpa));
    }

    printf("\nStudent details:\n");
    // Display student data
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("GPA: %.2f\n\n", students[i].gpa);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}


