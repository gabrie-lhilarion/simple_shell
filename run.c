#include "main.h"

void run(const char *command) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        char *args[] = { NULL, NULL };   
        char *envp[] = { NULL };

        args[0] = strdup(command); 

        if (args[0] == NULL) {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        execve(command, args, envp);

        
        fprintf(stderr, "%s: No such file or directory\n", command);

        free(args[0]);  
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}
