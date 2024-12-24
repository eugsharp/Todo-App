#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <ctype.h>
#include "data.h"

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

    char header[256];
    snprintf(header, sizeof(header), "%s MENU", time_frame);
    for (int i = 0; header[i]; i++) {
        header[i] = toupper(header[i]);
    }

    print_header(header);

    // display tasks
    display_tasks(time_frame);
    printf("----------------\n");
    print_header(time_frame);

    // ask user which task number to edit
    char task_number[256];
    printf("Enter task number to edit: ");
    scanf("%s", task_number);

    // get bounds (1 -> number of tasks)

    // input validation (ensure task number is an integer and within bounds)

    // ask user to enter their edits
    char line_number[256];
    printf("Enter new line: ");
    clear_input_buffer(); // clean input buffer so fgets can wait for input
    fgets(line_number, sizeof(line_number), stdin);
    
    // open file
    char filename[256]; 
    sprintf(filename, "entry-files/%s.txt", time_frame);

    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    // replace the respective line in file

    system("clear");
}

void delete_task(const char *time_frame) {
    
    // display menu header

    // display tasks

    // promt user for task number to delete

    // remove the respective line in file
}

