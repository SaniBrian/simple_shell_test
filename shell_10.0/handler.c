#include "shell.h"
/**
*handler - Handles executable
*@args: argument vector
*@prog: program name
*Return: return status 0 or 1
*/

void handler(char **args, char *prog)
{
	char *path;
	int b_ins;

	if (**args == 47)
	{
		execute(args[0], args, prog);
		return;
	}

	b_ins = check_builtins(args, prog);
	if (b_ins == 1)
		return;

	path = path_finder(*args);
	if (path != NULL)
	{
		execute(path, args, prog);
		free(path);
	} else
	{
		err_check(127, args);
		return;
	}
}
