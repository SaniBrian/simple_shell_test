#include "shell.h"

/**
*ffree - free malloc'ed space
*@args: Array of string pointer
*Return: void
*/

void ffree(char **args)
{
	int i = 0;

	if (!args || args == NULL)
		return;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
