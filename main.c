#include "main.h"

int main()
{
    char command[100];

    while(1)
    {
        show_prompt();
        read_command(command, sizeof(command));
        run(command);
    }


    return (0);
}