#include "main.h"

/**
 * main - The main program entry point.
 * Return: 0
 */

int main(void)
{
	char *command = NULL;
	size_t size = 0;

	while (1)
	{
		show_prompt();
		read_command(&command, &size);
		run(command);
	}

	free(command);

	return (0);
}
