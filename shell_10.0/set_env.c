#include "shell.h"

/**
*set_env - sets environment variable
*@args: vector of arguments
*@prog: program name
*Return: void
*/

void set_env(char **args, char *prog)
{
	int arg_count = 0, env_count = 0;
	char **tmp, *new_var;

	while (args[arg_count])
		arg_count++;
	if (arg_count < 3)
	{
		perror(prog);
		return;
	}
	while (environ[env_count])
		env_count++;
	tmp = malloc(sizeof(char *) * (env_count + 2));
	if (tmp == NULL)
	{
		perror(prog);
		return;
	}
	new_var = malloc(_strlen(args[1]) + _strlen(args[2]) + 2);
	if (new_var == NULL)
	{
		perror(prog);
		ffree(tmp);
		return;
	}
	_strcpy(new_var, args[1]);
	_strcat(new_var, "=");
	_strcat(new_var, args[2]);

	set_env_loop(new_var, tmp, args, prog);
}

/**
*set_env_loop - handles the env modifications
*@new_var: new variable
*@tmp: updated env variable
*@args: vector of arguments
*@prog: program name
*Return: void
*/
void set_env_loop(char *new_var, char **tmp, char **args, char *prog)
{
	int f_new = 0, i;
	char *cpy;

	for (i = 0; environ[i] != NULL; i++)
	{
		cpy = _strdup(environ[i]);
		if (cpy == NULL)
		{
			free(new_var);
			ffree(tmp);
			perror(prog);
			return;
		}
		if (compare_str(args[1], _strtok(cpy, "=")) == 1)
		{
			tmp[i] = new_var;
			f_new = 1;
		} else
		{
			tmp[i] = _strdup(environ[i]);
			if (tmp[i] == NULL)
			{
				free(cpy);
				ffree(tmp);
				free(new_var);
				perror(prog);
				return;
			}
		}
		free(cpy);
	}
	if (f_new == 0)
		tmp[i++] = new_var;
	tmp[i] = NULL;
	if (env.flag == 1)
		ffree(environ);
	env.flag = 1;
	environ = NULL;
	environ = tmp;
}
