#include "shell.h"

// Function to execute a command
void run_prompt(const char *command, const char *program_name) {
    char *cmd[] = { (char *)command, NULL };
    
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execve(command, cmd, environ) == -1) {
            fprintf(stderr, "%s: Command not found\n", program_name);
            exit(1);
        }
    } else {
        // Parent process
        wait(NULL);
    }
}