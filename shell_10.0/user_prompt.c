#include "shell.h"

/**
*user_prompt - prompt user and sets isatty flag
*@atty: isatty flag
*Return: void
*/

void user_prompt(int *atty)
{
	char prompt[] = "$ ";

	env.p_count++;
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		*atty = 1;
	else
		*atty = 0;
	if (*atty == 1)
		write(STDERR_FILENO, prompt, 2);
}
