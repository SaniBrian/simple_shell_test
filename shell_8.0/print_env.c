#include "shell.h"

/**
*print_env - prints env list
*@args: vector of arguments
*@prog: program name
*Return: void
*/

void print_env(char **args, char *prog)
{
	char **envp = environ;
	(void)args;

	if (envp == NULL)
		perror(prog);

	while (envp && *envp)
	{
		write(STDOUT_FILENO, *envp, _strlen(*envp));
		write(STDOUT_FILENO, "\n", 1);
		envp++;
	}
}
