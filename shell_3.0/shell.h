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
void handler(char **args, char *prog);
char *path_finder(char *exe);
char *append_path(char *s1, char *s2);
int _strlen(char *str);

#endif
