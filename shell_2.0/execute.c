#include "shell.h"

/**
*execute - execute a program
*@cp: command
*@args: arguments
*@prog: program name
*Return: void
*/
extern char** environ;

void execute(char *cp, char **args, char *prog)
{
	pid_t pid;
	int wait_status;
	char **envp = environ;

	pid = fork();
	if (pid == -1)
	{
		/**EROOR*/
		perror(prog);
		ffree(args);
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		/**CHILD PROCESS*/
		execve(cp, args, envp);
		ffree(args);
		perror(prog);
		exit(EXIT_FAILURE);
	} else
	{
		wait(&wait_status);
	}
}
