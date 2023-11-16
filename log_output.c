#include "main.h"

/**
 * log_output - logs messages to stadard out put.
 * @str: type char argument of strings
 */

void log_output(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
