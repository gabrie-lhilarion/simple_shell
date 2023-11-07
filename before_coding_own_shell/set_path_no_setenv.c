#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || value == NULL) {
        return -1; // Invalid input
    }

    char *env_var = getenv(name);

    if (env_var != NULL && !overwrite) {
        return 0; // Variable already exists, and overwrite is not allowed
    }

    char *env_str;
    size_t new_size = strlen(name) + 1 + strlen(value) + 1; // +1 for '=' and +1 for '\0'
    env_str = (char *)malloc(new_size);

    if (env_str == NULL) {
        return -1; // Memory allocation failed
    }

    snprintf(env_str, new_size, "%s=%s", name, value);

    if (env_var != NULL) {
        if (putenv(env_str) != 0) {
            free(env_str);
            return -1; // Failed to update the variable
        }
        free(env_var); // Free the old value
    } else {
        if (putenv(env_str) != 0) {
            free(env_str);
            return -1; // Failed to add the new variable
        }
    }

    return 0; // Variable successfully updated or added
}

int main() {
    const char *name = "CUSTOM_VARIABLE";
    const char *value = "new_value";

    printf("Before _setenv:\n");
    char *before = getenv(name);
    if (before) {
        printf("%s=%s\n", name, before);
    } else {
        printf("%s is not set.\n", name);
    }

    int result = _setenv(name, value, 1);

    if (result == 0) {
        printf("After _setenv:\n");
        char *after = getenv(name);
        printf("%s=%s\n", name, after);
    } else {
        printf("Error: Failed to set or update the environment variable.\n");
    }

    return 0;
}
