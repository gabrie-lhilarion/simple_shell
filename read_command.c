#include "main.h"

/**
 * read_command - function reads the input.
 * @command: the string provided
 * @size: the length of the string provided
 * Return: void
 */

void read_command(char **command, size_t *size)
{
	ssize_t bytes_read;
	int bytes_read;

	bytes_read = getline(command, size, stdin);
	if (bytes_read  == -1)
	{
		if (feof(stdin))
		{
			free(*command);
			log_output("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			log_output("Error reading input\n");
			exit(EXIT_FAILURE);
		}
	}

	(*command)[strcspn(*command, "\n")] = '\0';
}
