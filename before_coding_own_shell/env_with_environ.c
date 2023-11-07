#include <stdio.h>
#include <stdlib.h>

extern char **environ; // Declare the global variable environ

int main() {
    char **env = environ; // Create a local copy of environ

    while (*env != NULL) {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}