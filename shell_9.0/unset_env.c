#include "shell.h"

/**
*unset_env - unsets environment variable
*@args: vector of arguments
*@prog: program name
*Return: void
*/

void unset_env(char **args, char *prog)
{
	int arg_count = 0, env_count = 0;
	char **tmp;

	while (args[arg_count])
		arg_count++;
	if (arg_count < 2)
	{
		perror(prog);
		return;
	}
	while (environ[env_count])
		env_count++;
	tmp = malloc(sizeof(char *) * (env_count + 1));
	if (tmp == NULL)
	{
		perror(prog);
		return;
	}
	unset_env_loop(tmp, args, prog);
}

/**
*unset_env_loop - handles the unset loop
*@tmp: updated env variable
*@args: vector of arguments
*@prog: program name
*Return: void
*/
void unset_env_loop(char **tmp, char **args, char *prog)
{
	int i, j;
	char *cpy;

	for (i = 0, j = 0; environ[i] != NULL; j++, i++)
	{
		cpy = _strdup(environ[i]);
		if (cpy == NULL)
		{
			ffree(tmp);
			perror(prog);
			return;
		}
		if (compare_str(args[1], _strtok(cpy, "=")) == 1)
		{
			free(cpy);
			j--;
			continue;
		} else
		{
			tmp[j] = _strdup(environ[i]);
			if (tmp[j] == NULL)
			{
				free(cpy);
				ffree(tmp);
				perror(prog);
				return;
			}
		}
		free(cpy);
	}
	tmp[j] = NULL;
	if (env.flag == 1)
		ffree(environ);
	env.flag = 1;
	environ = NULL;
	environ = tmp;
}
