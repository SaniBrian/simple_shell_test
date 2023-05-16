#ifndef SHELL_H
#define SHELL_H

/**LIBRARY FUNCTION PROTO*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**FUNCTION PROTOTYPES*/
void user_prompt(int *atty);
void execute(char *cp, char **args, char *prog);
void ffree(char **args);

#endif
