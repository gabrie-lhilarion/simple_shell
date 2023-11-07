#include <stdio.h>
#include <string.h>

char *_getenv(const char *name) {
    extern char **environ; // Declare the global variable environ
    char **env = environ;  // Create a local copy of environ

    while (*env != NULL) {
        char *var = *env;
        if (strncmp(var, name, strlen(name)) == 0 && var[strlen(name)] == '=') {
            // Environment variable found; return the value part
            return var + strlen(name) + 1;
        }
        env++;
    }

    // Environment variable not found
    return NULL;
}

int main() {
    const char *varName = "PATH"; // Change to the name of the environment variable you want to retrieve
    char *value = _getenv(varName);

    if (value) {
        printf("Value of %s: %s\n", varName, value);
    } else {
        printf("Environment variable %s not found.\n", varName);
    }

    return 0;
}
