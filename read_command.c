#include "main.h"

void read_command(char *command, size_t size)
{
    if( fgets( command, size, stdin) == NULL)
    {
        if(feof(stdin))
        {
            log_output("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            log_output("Error reading input \n");
             exit(EXIT_FAILURE);
        }

    }

    command[strcspn(command, "\n")] = '\0';
}