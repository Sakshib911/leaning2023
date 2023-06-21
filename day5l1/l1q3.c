/*Write a function to sort the array of structures in descending order based on marks */
#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void sortStudents(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                // Swap the positions of two students
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void displayStudents(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents = 5;

    // Declare and initialize an array of structures
    struct Student students[5] = {
        {1001, "John", 95.5},
        {1002, "Alice", 88.0},
        {1003, "Bob", 75.5},
        {1004, "Emma", 91.0},
        {1005, "Mike", 82.5}
    };

    // Sort the array of structures in descending order based on marks
    sortStudents(students, numStudents);

    // Display the sorted array of structures
    displayStudents(students, numStudents);

    return 0;
}
