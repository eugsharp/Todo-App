#include <stdio.h>
#include <ctype.h>
#include "utils.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // discard characters
    }
}

int is_valid_integer(const char *str) {
    // Check if the string is empty or contains only whitespace
    if (str == NULL || *str == '\0' || isspace(*str)) {
        return 0;
    }

    // Check each character to ensure it is a digit
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}