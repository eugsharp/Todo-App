#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "features.h"
#include "data.h"

void sub_menu(const char* time_frame) { 
    char input[10];
    int choice;

    while (1) {

        update_array(time_frame);

        char header[256];
        
        print_header(time_frame);

        // Display all tasks
        display_tasks(time_frame);

        printf("----------------\n");
        
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Delete Task\n");
        printf("4. Back to Main Menu\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        // Validate choice to be an integer
        if (!is_valid_integer(input)) {
            system("clear");
            printf("Invalid input. Please enter a valid integer.\n");
            clear_input_buffer();
            continue;
        }

        // Convert choice to integer
        choice = atoi(input);

        switch (choice) {
            case 1:
                system("clear");
                add_task(time_frame);
                break;
            case 2:
                system("clear");
                edit_task(time_frame);
                break;
            case 3:
                system("clear");
                delete_task(time_frame);
                break;
            case 4:
                system("clear");
                return; // Go back to the main menu
            default:
                system("clear");
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    char input[10];
    int choice;

    system("clear");
    update_array("day");
    update_array("week");
    update_array("month");
    update_array("year");

    while (1) {
        print_header("main");
        printf("1. Days Menu\n");
        printf("2. Weeks Menu\n");
        printf("3. Months Menu\n");
        printf("4. Years Menu\n");
        printf("5. Exit\n");
        printf("----------------\n");
        printf("Enter your choice: ");
        scanf("%s", input);

        // Validate choice to be an integer
        if (!is_valid_integer(input)) {
            system("clear");
            printf("Invalid input. Please enter a valid integer.\n");
            clear_input_buffer();
            continue;
        }

        // Convert choice to integer
        choice = atoi(input);

        switch (choice) {
            case 1:
                system("clear");
                sub_menu("day");
                break;
            case 2:
                system("clear");
                sub_menu("week");
                break;
            case 3:
                system("clear");
                sub_menu("month");
                break;
            case 4:
                system("clear");
                sub_menu("year");
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                system("clear");
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}