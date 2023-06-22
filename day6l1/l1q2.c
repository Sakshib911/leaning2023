/*Case handler*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void convertToUpper(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }
}

void convertToLower(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(tolower(ch), destination);
    }
}

void convertToPurelyUpper(FILE *source, FILE *destination) {
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        if (isalpha(ch)) {
            fputc(toupper(ch), destination);
        } else {
            fputc(ch, destination);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options: -u (convert to upper case), -l (convert to lower case), -s (convert to purely upper case)\n");
        return 1;
    }

    FILE *sourceFile, *destinationFile;
    char option[3];
    char sourcePath[100], destinationPath[100];

    strncpy(option, argv[1], 3);
    option[2] = '\0';
    strncpy(sourcePath, argv[2], 100);
    strncpy(destinationPath, argv[3], 100);

    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    destinationFile = fopen(destinationPath, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpper(sourceFile, destinationFile);
    } else if (strcmp(option, "-l") == 0) {
        convertToLower(sourceFile, destinationFile);
    } else if (strcmp(option, "-s") == 0) {
        convertToPurelyUpper(sourceFile, destinationFile);
    } else {
        int ch;
        while ((ch = fgetc(sourceFile)) != EOF) {
            fputc(ch, destinationFile);
        }
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
