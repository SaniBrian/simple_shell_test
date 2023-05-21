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
	(void)prog;

	while (args[arg_count])
		arg_count++;

	if (arg_count > 1)
	{
		e_status = _atoi(args[1]);
		ffree(args);
		exit(e_status);
	}
	ffree(args);
	exit(0);
}
