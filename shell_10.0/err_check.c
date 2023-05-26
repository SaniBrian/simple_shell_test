#include "shell.h"

/**
 *err_check - handles chdir error
 *@err: error code
 *@args: args
 *Return: void
 */

int err_check(int err, char **args)
{
	char *_mssg = NULL;

	if (err == 2)
	{
		_mssg = "can't cd to ";
		cd_err_2(err, _mssg, args);
		return (1);
	}
	else if (err == 3)
	{
		_mssg = "Illegal number";
		cd_illegal(err, _mssg, args);
		return (1);
	}
	else
	{
		if (err == 13)
			_mssg = "Permission denied";
		else if (err == 127)
			_mssg = "not found";
		else if (err == 100)
			_mssg = "Unable to add/remove from environment";
		if (_mssg != NULL)
		{
			cd_err(err, _mssg, args);
			return (1);
		}
	}
	return (0);
}

/**
 *cd_err_2 - handles error 2
 *@err_no: error code
 *@e_msg: error message
 *@args: args
 *Return: void
 */

void cd_err_2(int err_no, char *e_msg, char **args)
{
	char *message, *p_count_str;
	int len;
	(void)err_no;

	len = _strlen(env.p_name) + int_len(env.p_count) + _strlen(args[1]);
	len = len + _strlen(e_msg) + _strlen(args[0]);
	message = malloc(sizeof(char) * (len + 7));
	if (message == NULL)
	{
		perror(env.p_name);
		return;
	}
	p_count_str = _itoa(env.p_count);
	_strcpy(message, env.p_name);
	_strcat(message, ": ");
	_strcat(message, p_count_str);
	_strcat(message, ": ");
	_strcat(message, args[0]);
	_strcat(message, ": ");
	_strcat(message, e_msg);
	_strcat(message, args[1]);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
	free(p_count_str);
	free(message);
	message = NULL;
}

/**
 *cd_err - handles error
 *@err_no: error number
 *@e_msg: error message
 *@args: args
 *Return: void
 */

void cd_err(int err_no, char *e_msg, char **args)
{
	char *message, *p_count_str;
	int len;
	(void)err_no;

	len = _strlen(env.p_name) + int_len(env.p_count) + _strlen(args[0]);
	len = len + _strlen(e_msg);
	message = malloc(sizeof(char) * (len + 7));
	if (message == NULL)
	{
		perror(env.p_name);
		return;
	}
	p_count_str = _itoa(env.p_count);
	_strcpy(message, env.p_name);
	_strcat(message, ": ");
	_strcat(message, p_count_str);
	_strcat(message, ": ");
	_strcat(message, args[0]);
	_strcat(message, ": ");
	_strcat(message, e_msg);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
	free(p_count_str);
	free(message);
	message = NULL;
}

/**
 *cd_illegal - handles illegal cd error
 *@err_no: error code
 *@e_msg: error message
 *@args: args
 *Return: void
 */
void cd_illegal(int err_no, char *e_msg, char **args)
{
	char *message, *p_count_str;
	int len;
	(void)err_no;

	len = _strlen(env.p_name) + int_len(env.p_count) + _strlen(args[1]);
	len = len + _strlen(e_msg) + _strlen(args[0]);
	message = malloc(sizeof(char) * (len + 9));
	if (message == NULL)
	{
		perror(env.p_name);
		return;
	}
	p_count_str = _itoa(env.p_count);
	_strcpy(message, env.p_name);
	_strcat(message, ": ");
	_strcat(message, p_count_str);
	_strcat(message, ": ");
	_strcat(message, args[0]);
	_strcat(message, ": ");
	_strcat(message, e_msg);
	 _strcat(message, ": ");
	_strcat(message, args[1]);
	write(STDERR_FILENO, message, _strlen(message));
	write(STDERR_FILENO, "\n", 1);
	free(p_count_str);
	free(message);
	message = NULL;
}
