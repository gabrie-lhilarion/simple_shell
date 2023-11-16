#include "main.h"

void read_command(char **command, size_t *size) {
    ssize_t bytes_read;

    if ((bytes_read = getline(command, size, stdin)) == -1) {
        if (feof(stdin)) {
           
            free(*command);
            log_output("\n");
            exit(EXIT_SUCCESS);
        } else {
           
            log_output("Error reading input\n");
            exit(EXIT_FAILURE);
        }
    }

    (*command)[strcspn(*command, "\n")] = '\0';
}