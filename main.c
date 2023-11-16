#include "main.h"

int main()
{
    char *command = NULL;
    size_t size = 0;

 while (1) {
    show_prompt();
    read_command(&command, &size);
    run(command);
}

free(command);

    return (0);
}