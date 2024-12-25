#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <ctype.h>
#include "data.h"
#include <string.h>

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

    update_array(time_frame);

    system("clear");

    // print array for debug
    // for (int i = 0; i < 256; i++) {
    //     printf("%d. %s\n", i, day_tasks[i]);
    // }
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

    // ask user which task number to edit
    char task_number[256];
    printf("Enter task number to edit: ");
    scanf("%s", task_number);

    // get bounds (1 -> number of tasks)

    // input validation (ensure task number is an integer and within bounds)

    // ask user to enter their edits
    char edited_line[256];
    printf("Enter new line: ");
    clear_input_buffer(); // clean input buffer so fgets can wait for input
    fgets(edited_line, sizeof(edited_line), stdin);
    
    // REPLACE RESPECTIVE LINE IN FILE
    // get the appropriate array
    char task_array[256][256];
    if (strcmp(time_frame, "day") == 0){
        for (int i = 0; i < 256; i++) {
            strcpy(task_array[i], day_tasks[i]);
        }
    } else if (strcmp(time_frame, "week") == 0){
        for (int i = 0; i < 256; i++) {
            strcpy(task_array[i], week_tasks[i]);
        }
    } else if (strcmp(time_frame, "month") == 0){
        for (int i = 0; i < 256; i++) {
            strcpy(task_array[i], month_tasks[i]);
        }
    } else if (strcmp(time_frame, "year") == 0){
        for (int i = 0; i < 256; i++) {
            strcpy(task_array[i], year_tasks[i]);
        }
    }

    system("clear");
    // print the task array for debug
    for (int i = 0; i < 256; i++) {
        printf("%d. %s\n", i, task_array[i]);
    }
    
    // change the respective term in array
    strcpy(task_array[atoi(task_number) - 1], edited_line);

    // place each term in array back to file
    // open file
    char filename[256]; 
    sprintf(filename, "entry-files/%s.txt", time_frame);

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // for (int i = 0; i < 256; i++) {
    //     fprintf(file, "%s", task_array[i]);
    // }
    
    fclose(file);
}

void delete_task(const char *time_frame) {
    
    // display menu header

    // display tasks

    // promt user for task number to delete

    // remove the respective line in file
}

