#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent an environment variable
struct EnvironmentVar {
    char *name;
    char *value;
};

// An array to store environment variables
struct EnvironmentVar *custom_environ;
int custom_environ_size = 0;

// Function to add an environment variable to the custom environment
int addEnvironmentVar(const char *name, const char *value) {
    struct EnvironmentVar *new_vars = (struct EnvironmentVar *)realloc(custom_environ, (custom_environ_size + 1) * sizeof(struct EnvironmentVar));
    if (new_vars == NULL) {
        return -1; // Memory allocation failed
    }

    custom_environ = new_vars;
    custom_environ[custom_environ_size].name = strdup(name);
    custom_environ[custom_environ_size].value = strdup(value);
    custom_environ_size++;
    return 0;
}

// Function to remove an environment variable from the custom environment
int removeEnvironmentVar(const char *name) {
    for (int i = 0; i < custom_environ_size; i++) {
        if (strcmp(custom_environ[i].name, name) == 0) {
            free(custom_environ[i].name);
            free(custom_environ[i].value);
            if (i < custom_environ_size - 1) {
                // Move remaining elements to fill the gap
                memmove(&custom_environ[i], &custom_environ[i + 1], (custom_environ_size - i - 1) * sizeof(struct EnvironmentVar));
            }
            custom_environ_size--;
            return 0;
        }
    }
    return -1; // Variable not found
}

// Function to print the custom environment
void printCustomEnvironment() {
    for (int i = 0; i < custom_environ_size; i++) {
        printf("%s=%s\n", custom_environ[i].name, custom_environ[i].value);
    }
}

int _unsetenv(const char *name) {
    if (name == NULL) {
        return -1; // Invalid input
    }

    int result = removeEnvironmentVar(name);
    return result;
}

int main() {
    custom_environ = NULL;

    // Initialize the custom environment with some variables
    addEnvironmentVar("VAR1", "Value1");
    addEnvironmentVar("VAR2", "Value2");
    addEnvironmentVar("VAR3", "Value3");

    const char *name = "VAR2";

    printf("Before _unsetenv:\n");
    printCustomEnvironment();

    int result = _unsetenv(name);

    if (result == 0) {
        printf("After _unsetenv:\n");
        printCustomEnvironment();
    } else {
        printf("Error: Failed to unset the environment variable.\n");
    }

    // Free memory allocated for the custom environment
    for (int i = 0; i < custom_environ_size; i++) {
        free(custom_environ[i].name);
        free(custom_environ[i].value);
    }
    free(custom_environ);

    return 0;
}
