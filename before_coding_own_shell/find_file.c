#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename ...\n", argv[0]);
        return 1;
    }

    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH environment variable not set.\n");
        return 1;
    }

    char *token = strtok(path, ":");
    while (token != NULL) {
        for (int i = 1; i < argc; i++) {
            char filepath[1024]; // Adjust the buffer size as needed
            snprintf(filepath, sizeof(filepath), "%s/%s", token, argv[i]);

            if (access(filepath, F_OK) == 0) {
                printf("%s\n", filepath);
            }
        }
        token = strtok(NULL, ":");
    }

    return 0;
}