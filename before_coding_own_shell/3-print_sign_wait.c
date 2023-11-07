#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[1024]; // Maximum command length

    while (1) {
        printf("$ ");
        fflush(stdout); // Flush the output to ensure it's displayed

        if (fgets(command, sizeof(command), stdin) == NULL) {
            break; // Exit if there's no input
        }

        // Remove the trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Check if the user entered "exit" to quit the loop
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Print the entered command on the next line
        printf("You entered: %s\n", command);
    }

    return 0;
}