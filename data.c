#include <stdio.h>
#include "data.h"  
#include <string.h>

void update_array(const char *time_frame) {
    // open file
    char filename[256]; 
    sprintf(filename, "entry-files/%s.txt", time_frame);
    
    // empty array first
    for (int i = 0; i < 256; i++) {
        day_tasks[i][0] = '\0';
        week_tasks[i][0] = '\0';
        month_tasks[i][0] = '\0';
        year_tasks[i][0] = '\0';
    }

    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // read file line by line
    char line[256];
    int index = 0;
    while (fgets(line, sizeof(line), file)) {
        
        // copy line to array (depending on timeframe specifed)
       if (strcmp(time_frame, "day") == 0) {
            strcpy(day_tasks[index], line);
        } else if (strcmp(time_frame, "week") == 0) {
            strcpy(week_tasks[index], line);
        } else if (strcmp(time_frame, "month") == 0) {
            strcpy(month_tasks[index], line);
        } else if (strcmp(time_frame, "year") == 0) {
            strcpy(year_tasks[index], line);
       }

        index++;
    }

    // print array for debug
    // for (int i = 0; i < 256; i++) { 
    //     printf("%s", day_tasks[i]);
    // }
}

int get_num_of_tasks(const char* time_frame) { 

    int num_of_tasks = 0;

    // open file
    char filename[256]; 
    sprintf(filename, "entry-files/%s.txt", time_frame);
    FILE* file = fopen(filename, "r");

    if (file == NULL) { 
        perror("Error opening file");
        return 0;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] != '\n') {
            num_of_tasks++;
        }
    }

    return num_of_tasks;
}