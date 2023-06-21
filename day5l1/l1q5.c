/* Write a function to perform a search operation on the array of structures based on name of the student */
#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student* students, int numStudents, const char* name) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n", name);
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

    // Search for a student by name
    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    searchStudentByName(students, numStudents, searchName);

    return 0;
}
