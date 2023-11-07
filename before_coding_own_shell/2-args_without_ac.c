#include <stdio.h>

int main(int argc, char *argv[]) {
    char **arg = argv;
    int i = 0;

    while (arg[i]) {
        printf("%s\n", arg[i]);
        i++;
    }

    return 0;
}