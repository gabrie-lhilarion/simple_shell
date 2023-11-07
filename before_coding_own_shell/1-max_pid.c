#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *pid_max_file = fopen("/proc/sys/kernel/pid_max", "r");
    long max_pid;

    if (pid_max_file == NULL) {
        perror("fopen");
        printf("Failed to open /proc/sys/kernel/pid_max\n");
        return 1;
    }

    if (fscanf(pid_max_file, "%ld", &max_pid) != 1) {
        perror("fscanf");
        printf("Failed to read the value from /proc/sys/kernel/pid_max\n");
        fclose(pid_max_file);
        return 1;
    }

    fclose(pid_max_file);

    printf("Maximum PID: %ld\n", max_pid);
    return 0;
}