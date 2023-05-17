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

	if (**args == 47)
	{
		execute(args[0], args, prog);
		return;
	}
	path = path_finder(*args);
	if (path != NULL)
	{
		execute(path, args, prog);
		free(path);
	} else
	{
		perror(prog);
		return;
	}
}
