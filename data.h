#ifndef DATA_H
#define DATA_H

char day_tasks[256][256];
char week_tasks[256][256];
char month_tasks[256][256];
char year_tasks[256][256];

void update_array(const char *time_frame);
int get_num_of_tasks(const char* time_frame);

#endif // DATA_H