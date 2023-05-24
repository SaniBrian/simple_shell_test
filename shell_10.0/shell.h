#ifndef SHELL_H
#define SHELL_H

/**LIBRARY FUNCTION PROTO*/
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>

/**ENVIRONMENT VARIABLE*/
extern char **environ;

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
void set_env(char **args, char *prog);
char *_strcat(char *s1, char *s2);
char *_strcpy(char *s1, char *s2);
void set_env_loop(char *new_var, char **tmp, char **args, char *prog);
void unset_env(char **args, char *prog);
void unset_env_loop(char **tmp, char **args, char *prog);
void signal_handler(int signal);
void cd_dir(char **args, char *prog);
void chng_env(char *var, char *v_name, char *prog);
void chng_env_loop(char *new_var, char *v_name, char **tmp, char *prog);
void cd_absolute(char **args, char *pwd, char *prog);
int err_check(int err, char **args);
void cd_err_2(int err_no, char *e_msg, char **args);
void cd_err(int err_no, char *e_msg, char **args);
char *_itoa(int num);
int int_len(int num);
int cd_slash(char **args, char *pwd);
void getline_fail(char **env, char *buf);

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

/**ENV FLAG STRUCT*/
/**
*struct Env - env global flag struct
*@flag: flag
*/
struct Env
{
	int flag;
	int p_count;
	char *p_name;
} env;


#endif
