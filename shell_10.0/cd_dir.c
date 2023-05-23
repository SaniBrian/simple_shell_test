#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
/**
*cd_dir - change directory
*@args: vectors of args
*@prog: program name
*Return: void
*/
void cd_dir(char **args, char *prog)
{
	int arg_count = 0, err;
	char *nnew = "PWD", *old = "OLDPWD", *pwd = NULL, *oldpwd;

	pwd = getcwd(pwd, 0);
	oldpwd = getenv("OLDPWD");
	if (oldpwd == NULL)
		oldpwd = pwd;

	while (args[arg_count] != NULL)
		arg_count++;
	if (arg_count == 1)
	{
		if (!getenv("HOME"))
		{
			perror(prog);
			return;
		}
		chdir(getenv("HOME"));
		chng_env(pwd, old, prog);
		chng_env(getenv("HOME"), nnew, prog);
	} else if (args[1][0] == 47)/** / */
	{
		err = chdir(args[1]);
		if (err_check(err, prog) == 1)
			return;
		chng_env(pwd, old, prog);
		chng_env(args[1], nnew, prog);
	} else if (args[1][0] == '-')
	{
		chdir(oldpwd);
		chng_env(oldpwd, nnew, prog);
		chng_env(pwd, old, prog);
		oldpwd = getenv("PWD");
		write(STDOUT_FILENO, oldpwd, _strlen(oldpwd));
		write(STDOUT_FILENO, "\n", 1);
	} else
		cd_absolute(args, pwd, prog);
	free(pwd);
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
	int i, v_found = 0;
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
			v_found = 1;
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
	if (!v_found)
		tmp[i++] = new_var;
	tmp[i] = NULL;
	if (env.flag == 1)
		ffree(environ);
	env.flag = 1;
	environ = NULL;
	environ = tmp;
}

/**
 *cd_absolute - generate and cd into absolute path
 *@args: vectors of args
 *@pwd: current working directory
 *@prog: program name
 *Return: void
 */

void cd_absolute(char **args, char *pwd, char *prog)
{
	char *f_path = NULL;
	char *nnew = "PWD", *old = "OLDPWD", *n_pwd = NULL;
	int i = 0, err;

	f_path = malloc(_strlen(pwd) + _strlen(args[1]) + 2);
	if (f_path == NULL)
	{
		perror(prog);
		return;
	}
	_strcpy(f_path, pwd);
	while (f_path[i] != '\0')
		i++;
	if ((f_path[i - 1]) != 47)
	{
		f_path[i++] = '/';
		f_path[i] = '\0';
	}
	_strcat(f_path, args[1]);
	err = chdir(f_path);
	if (err_check(err, prog) == 1)
	{
		free(f_path);
		return;
	}
	n_pwd = getcwd(n_pwd, 0);
	/**
	 *n_pwd is the dir we just cd into
	 *pwd is our current dir passed down from our main cd function
	 */
	chng_env(n_pwd, nnew, prog);
	chng_env(pwd, old, prog);
	free(n_pwd);
	free(f_path);
}

/**
 *err_check - handles chdir error
 *@err: error code
 *@prog: program name
 *Return: void
 */

int err_check(int err, char *prog)
{
	if (err != 0)
	{
		perror(prog);
		return (1);
	}
	return (0);
}
