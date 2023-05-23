#include "shell.h"

/**
*check_builtins - check for builtins
*@args: arguments
*@prog: program name
*Return: 0 if no b_ins found, 1 if otherwise
*/


int check_builtins(char **args, char *prog)
{
	int i = 0, cmp;

	Builtins builtins[] = {
		{"exit", exit_0},
		{"env", print_env},
		{"setenv", set_env},
		{"unsetenv", unset_env},
		{"cd", cd_dir},
		{NULL, NULL}
	};

	while (builtins[i].name != NULL)
	{
		cmp = compare_str(builtins[i].name, args[0]);
		if (cmp == 1)
		{
			builtins[i].funct(args, prog);
			return (1);
		}
		i++;
	}
	return (0);
}
