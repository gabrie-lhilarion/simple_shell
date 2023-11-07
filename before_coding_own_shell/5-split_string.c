#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **splitString(const char *input) {
    if (!input) {
        return NULL;
    }

    // Determine the maximum number of words in the input (maximum word count = character count)
    int wordCount = strlen(input);

    // Allocate memory for the array of word pointers
    char **words = (char **)malloc((wordCount + 1) * sizeof(char *)); // +1 for the NULL pointer
    if (!words) {
        return NULL; // Memory allocation failed
    }

    int wordIndex = 0; // Index for the current word
    int charIndex = 0; // Index for the current character in the input

    while (input[charIndex] != '\0') {
        // Skip leading spaces
        while (input[charIndex] == ' ' || input[charIndex] == '\t') {
            charIndex++;
        }

        // Start of a word
        int wordStart = charIndex;

        // Find the end of the word
        while (input[charIndex] != ' ' && input[charIndex] != '\t' && input[charIndex] != '\0') {
            charIndex++;
        }

        // Check if a word was found
        if (charIndex > wordStart) {
            // Allocate memory for the word and copy it
            int wordLength = charIndex - wordStart;
            words[wordIndex] = (char *)malloc(wordLength + 1);
            if (!words[wordIndex]) {
                // Memory allocation failed
                for (int i = 0; i < wordIndex; i++) {
                    free(words[i]);
                }
                free(words);
                return NULL;
            }

            strncpy(words[wordIndex], input + wordStart, wordLength);
            words[wordIndex][wordLength] = '\0';
            wordIndex++;
        }
    }

    // Terminate the array with a NULL pointer
    words[wordIndex] = NULL;

    return words;
}

void freeWordArray(char **words) {
    if (!words) {
        return;
    }

    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    const char *input = "This is a sample string";
    char **words = splitString(input);

    if (words) {
        printf("Words in the string:\n");
        for (int i = 0; words[i] != NULL; i++) {
            printf("%d: %s\n", i + 1, words[i]);
        }

        // Free the allocated memory
        freeWordArray(words);
    } else {
        printf("Failed to split the string.\n");
    }

    return 0;
}
