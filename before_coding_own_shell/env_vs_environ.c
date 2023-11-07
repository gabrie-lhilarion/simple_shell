#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char *argv[], char *envp[]) {
    // Print the address of the envp (the third parameter)
    printf("Address of envp (the third parameter): %p\n", (void *)envp);

    // Print the address of the global variable environ
    printf("Address of environ (the global variable): %p\n", (void *)environ);

    return 0;
}