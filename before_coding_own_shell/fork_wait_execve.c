#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 5; i++) {
        pid_t child_pid = fork();

        if (child_pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        } else if (child_pid == 0) {
            // This code is executed by the child process
            printf("Child %d (PID %d) is running ls -l /tmp:\n", i + 1, getpid());
            execlp("ls", "ls", "-l", "/tmp", NULL);
            // If execlp fails, the child process will terminate
            perror("execlp");
            exit(EXIT_FAILURE);
        } else {
            // This code is executed by the parent process
            int status;
            waitpid(child_pid, &status, 0); // Wait for the child to exit
            if (WIFEXITED(status)) {
                printf("Child %d (PID %d) exited with status %d\n", i + 1, child_pid, WEXITSTATUS(status));
            } else {
                printf("Child %d (PID %d) did not exit normally\n", i + 1, child_pid);
            }
        }
    }

    return 0;
}