#include "main.h"

void log_output(const char *str) 
{
    write(STDOUT_FILENO, str, strlen(str));
}
