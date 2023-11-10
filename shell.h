#ifndef SHELL_H 
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;  

#define MAX_INPUT_SIZE 100

#define PROMPT "$ "

void run_prompt(const char *command, const char *program_name);

#endif