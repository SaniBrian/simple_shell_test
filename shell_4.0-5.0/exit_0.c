#include "shell.h"

void exit_0(char **args, char *prog)
{
	(void)prog;

	ffree(args);
	exit(0);
}
