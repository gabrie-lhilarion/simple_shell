#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream) {
    if (!lineptr || !n || !stream) {
        return -1; // Invalid arguments
    }

    char *line = NULL;
    size_t size = 0;
    int ch;
    ssize_t length = 0;

    while ((ch = fgetc(stream)) != EOF && ch != '\n') {
        if (size <= (size_t)length + 1) {
            size = size ? size * 2 : 64; // Initial size or double the current size
            char *temp = (char *)realloc(line, size);
            if (!temp) {
                free(line);
                return -1; // Memory allocation failed
            }
            line = temp;
        }

        line[length++] = (char)ch;
    }

    if (length == 0 && ch == EOF) {
        return -1; // No characters read (EOF)
    }

    if (size <= (size_t)length + 1) {
        size = size ? size * 2 : 64;
        char *temp = (char *)realloc(line, size);
        if (!temp) {
            free(line);
            return -1; // Memory allocation failed
        }
        line = temp;
    }

    line[length] = '\0';

    if (*lineptr) {
        free(*lineptr);
    }
    
    *lineptr = line;
    *n = size;
    
    return length;
}