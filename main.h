#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void log_output(const char *str);
void show_prompt(void);
void run(const char *command);
void read_command(char **command, size_t *size);



#endif

