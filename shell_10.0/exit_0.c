#include "shell.h"

/**
*exit_0 - exit handler
*@args: args vector
*@prog: program name
*Return: void
*/

void exit_0(char **args, char *prog)
{
	int arg_count = 0, e_status;
	char *arg_val;
	(void)prog;

	while (args[arg_count])
		arg_count++;

	if (arg_count > 1)
	{
		arg_val = args[1];
		while (*arg_val != '\0')
		{
			if (*arg_val < '0' || *arg_val > '9')
			{
				err_check(3, args);
				return;
			}
			arg_val++;
		}
		e_status = _atoi(args[1]);
		ffree(args);
		if (env.flag)
			ffree(environ);
		exit(e_status);
	}
	ffree(args);
	if (env.flag)
		ffree(environ);
	exit(0);
}
