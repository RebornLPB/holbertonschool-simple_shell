#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

char **split_string(char *str);
int execute_command(char **av, char *buffer, int compt);
char *_getenv(const char *name);
char *_wich(const char *command);
int handle_exit(char **av, char *buffer);
extern char **environ;

#endif
