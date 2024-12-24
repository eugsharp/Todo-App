#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <ctype.h>

// time frame is either days, weeks, months, or years
void display_tasks(const char* time_frame) {
    // read file based on argument
    char filename[256]; // Ensure the buffer is large enough
    sprintf(filename, "entry-files/%s.txt", time_frame);

    FILE* file = fopen(filename, "r"); // Use the correct filename
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[256]; // Ensure the buffer is large enough

    int index = 1;
    while (fgets(line, sizeof(line), file)) {

        // ignore empty lines
        if (line[0] == '\n') {
            continue;
        }

        printf("%d. %s", index, line);
        index++;
    }
    printf("\n");

    fclose(file);
}

void add_task(const char *time_frame) {
    
    // display menu header
    char header[256];
    snprintf(header, sizeof(header), "%s MENU", time_frame);
    for (int i = 0; header[i]; i++) {
        header[i] = toupper(header[i]);
    }

    print_header(header);

    // display tasks
    display_tasks(time_frame);
    printf("----------------\n");

    // prompt user for task 
    char task[256];
    printf("Enter task: ");
    clear_input_buffer(); // clean input buffer so fgets can wait for input
    fgets(task, sizeof(task), stdin);
    //scanf("%s", task);

    // write task to file
    char filename[256]; 
    sprintf(filename, "entry-files/%s.txt", time_frame);

    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "%s", task);
    fclose(file);

    system("clear");
}

void edit_task(const char *time_frame) {
    printf("Edit Task\n");
}

void delete_task(const char *time_frame) {
    printf("Delete Task\n");
}

