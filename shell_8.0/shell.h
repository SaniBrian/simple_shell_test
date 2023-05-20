#ifndef SHELL_H
#define SHELL_H

/**ENVIRONMENT VARIABLE*/
extern char **environ;

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
int check_builtins(char **args, char *prog);
int compare_str(char *s1, char *s2);
void exit_0(char **args, char *prog);
void print_env(char **args, char *prog);
int _atoi(char *s);

/**BUILT_INS STRUCT*/
/**
*struct builtins - builtins name and function structure
*@name: name of builtin
*@funct: Function of builtin
*/
typedef struct builtins
{
	char *name;

	void (*funct)(char **args, char *prog);

} Builtins;

#endif
