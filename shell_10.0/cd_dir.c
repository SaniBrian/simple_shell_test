#include "shell.h"
#include <stdlib.h>
/**
*cd_dir - change directory
*@args: vectors of args
*@prog: program name
*Return: void
*/
void cd_dir(char **args, char *prog)
{
	int arg_count = 0, i = 0;
	char *pwd = "PWD", *owd = "OLDPWD", *tmp, *f_path;

	while (args[arg_count] != NULL)
		arg_count++;
	if (arg_count == 1)
	{
		chdir(getenv("HOME"));
		chng_env(getenv("PWD"), owd, prog);
		chng_env(getenv("HOME"), pwd, prog);
	} else if (args[1][0] == 47)/** / */
	{
		chdir(args[1]);
		chng_env(getenv("PWD"), owd, prog);
		chng_env(args[1], pwd, prog);
	} else if (args[1][0] == '-')
	{
		chdir(getenv("OLDPWD"));
		tmp = _strdup(getenv("PWD"));
		chng_env(getenv("OLDPWD"), pwd, prog);
		chng_env(tmp, owd, prog);
		free(tmp);
	} else
	{
		tmp = malloc(_strlen(getenv("PWD")) + 1);
		_strcpy(tmp, getenv("PWD"));
		f_path = malloc(_strlen(tmp) + _strlen(args[1]) + 2);
		_strcpy(f_path, tmp);
		while (f_path[i] != '\0')
			i++;
		if ((f_path[i - 1]) != 47)
		{
			f_path[i++] = '/';
			f_path[i] = '\0';
		}
		_strcat(f_path, args[1]);
		chdir(f_path);
		chng_env(getenv("PWD"), owd, prog);
		chng_env(f_path, pwd, prog);
		free(tmp);
		free(f_path);
	}
}

/**
*chng_env - changes PWD environment variable
*@var: new PWD path
*@v_name: name of variable
*@prog: program name
*Return: void
*/
void chng_env(char *var, char *v_name, char *prog)
{
	int env_count = 0;
	char **tmp, *new_var;

	while (environ[env_count])
		env_count++;
	tmp = malloc(sizeof(char *) * (env_count + 2));
	if (tmp == NULL)
	{
		perror(prog);
		return;
	}
	new_var = malloc(_strlen(v_name) + _strlen(var) + 2);
	if (new_var == NULL)
	{
		perror(prog);
		ffree(tmp);
		return;
	}
	_strcpy(new_var, v_name);
	_strcat(new_var, "=");
	_strcat(new_var, var);
	chng_env_loop(new_var, v_name, tmp, prog);
}

/**
*chng_env_loop - chng_env loop
*@new_var: new PWD path
*@v_name: name of variable e.g PWD
*@tmp: temp env list
*@prog: program name
*Return: void
*/
void chng_env_loop(char *new_var, char *v_name, char **tmp, char *prog)
{
	int i;
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
		if (compare_str(v_name, _strtok(cpy, "=")) == 1)
		{
			tmp[i] = new_var;
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
	tmp[i] = NULL;
	if (env.flag == 1)
		ffree(environ);
	env.flag = 1;
	environ = NULL;
	environ = tmp;
}
