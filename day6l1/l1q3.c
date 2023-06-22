/* Data Viewer*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[10];
} LogEntry;

void extractLogEntries(const char* filename, LogEntry entries[], int* count) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file '%s'.\n", filename);
        *count = 0;
        return;
    }

    char line[256];
    *count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file)) {
        // Remove the trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line using commas as delimiters
        char* token = strtok(line, ",");
        if (token == NULL) {
            continue;  // Skip empty lines
        }

        entries[*count].entryNo = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entries[*count].sensorNo, token, sizeof(entries[*count].sensorNo));

        token = strtok(NULL, ",");
        entries[*count].temperature = atof(token);

        token = strtok(NULL, ",");
        entries[*count].humidity = atoi(token);

        token = strtok(NULL, ",");
        entries[*count].light = atoi(token);

        token = strtok(NULL, ",");
        strncpy(entries[*count].time, token, sizeof(entries[*count].time));

        (*count)++;

        if (*count >= MAX_ENTRIES) {
            break;  // Maximum number of entries reached
        }
    }

    fclose(file);
}

void displayLogEntries(const LogEntry entries[], int count) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTime\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               entries[i].entryNo,
               entries[i].sensorNo,
               entries[i].temperature,
               entries[i].humidity,
               entries[i].light,
               entries[i].time);
    }
}

int main() {
    LogEntry entries[MAX_ENTRIES];
    int count;

    extractLogEntries("data.csv", entries, &count);

    displayLogEntries(entries, count);

    return 0;
}
