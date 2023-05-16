#ifndef SHELL_H
#define SHELL_H

/**LIBRARY FUNCTION PROTO*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/**FUNCTION PROTOTYPES*/
char *_strtok(char *string, char *dlm);
void user_prompt(int *atty);
void execute(char *cp, char **args, char *prog);
void ffree(char **args);
char **split_buffer(char *buffer);
char *_strdup(char *str);
char **_realloc(char **list, size_t size, int count);


#endif
