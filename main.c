#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

void days_menu() { 
    char inpiut[] = "";
    int choice;

    printf("----------------\n");
    printf("    DAYS MENU\n");
    printf("----------------\n");

    // display all tasks

    printf("1. Add Task\n");
    printf("2. Edit Task\n");
    printf("3. Delete Task\n");
    printf("4. Back\n");
    printf("----------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
}

int main() { 
    char input[] = "";
    int choice;

    while (1) {
        printf("----------------\n");
        printf("   MAIN MENU\n");
        printf("----------------\n");
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
            printf("\nInvalid input. Please enter a valid integer.\n");
            clear_input_buffer();
            continue;
        }

        // Convert choice to integer
        choice = atoi(input);

        switch(choice) {
            case 1:
                days_menu();
                break;
            case 2:
                printf("Weeks Menu\n");
                break;
            case 3:
                printf("Months Menu\n");
                break;
            case 4:
                printf("Years Menu\n");
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    }

    return 0;
}