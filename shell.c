#include "shell.h"


int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    while (1) {
        printf(PROMPT);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            if (feof(stdin)) {
                printf("\n");
                exit(0);
            } else {
                perror("fgets");
                exit(1);
            }
        }

        size_t input_len = strlen(input);
        if (input_len > 0 && input[input_len - 1] == '\n') {
            input[input_len - 1] = '\0';
        }

        if (input[0] != '\0') {
            run_prompt(input, argv[0]);
        }
    }

    return 0;
}