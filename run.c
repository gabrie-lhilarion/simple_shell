#include "main.h"

/**
 * run - function that rus the command.
 * @command: type int argument
 * Return: void
 */

void run(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0)
	{
		char *args[100];
		char *token;
		int i = 0;

		token = strtok((char *)command, " \t\n");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " \t\n");
		}

		args[i] = NULL;
		execve(args[0], args, NULL);

		fprintf(stderr, "%s: No such file or directory\n", args[0]);
		exit(EXIT_FAILURE);
	} else
	{
		wait(NULL);
	}
}
