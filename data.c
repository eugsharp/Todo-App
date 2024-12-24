#include <stdio.h>
#include "data.h"  

void update_array(const char *time_frame) {
    // open file
    char filename[256]; 
    sprintf(filename, "entry-files/%s.txt", time_frame);

    FILE* file = fopen(filename, 'r');

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // read file line by line
    char line[256];
    int index = 0;
    while (fgets(line, sizeof(line), file)) {
        
        if (line[0] == '\n') {
            continue;
        }

        // copy line to array (depending on timeframe specifed)
       if (time_frame == "day") {
            strcpy(day_tasks[index], line);
        } else if (time_frame == "week") {
            strcpy(week_tasks[index], line);
        } else if (time_frame == "month") {
            strcpy(month_tasks[index], line);
        } else if (time_frame == "year") {
            strcpy(year_tasks[index], line);
       }

        index++;
    }
}