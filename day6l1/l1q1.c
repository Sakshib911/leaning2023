/*1. File Copy: Write a C program to copy a file using file operations*/
#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourcePath[100], destinationPath[100];
    char ch;

    // Get the source file path
    printf("Enter the path of the source file: ");
    scanf("%s", sourcePath);

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "r");

    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Get the destination file path
    printf("Enter the path of the destination file: ");
    scanf("%s", destinationPath);

    // Open the destination file in write mode
    destinationFile = fopen(destinationPath, "w");

    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
