#include "shell.h"

/**
*execute - execute a program
*@cp: command
*@args: arguments
*@prog: program name
*Return: void
*/

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
		if (env.flag)
			ffree(environ);
		exit(1);
	} else if (pid == 0)
	{
		/**CHILD PROCESS*/
		execve(cp, args, envp);
		if (err_check(errno, args) == 0)
			perror(env.p_name);
		ffree(args);
		if (env.flag)
			ffree(environ);
		args = NULL;
		exit(1);
	} else
	{
		wait(&wait_status);
	}
}
