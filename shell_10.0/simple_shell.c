#include "shell.h"

/**
*main - Entry point to our shell program
*@ac: args count
*@argv: array of args
*Return: 0 on success termination, non zero value if otherwise
*/

int main(int ac, char **argv)
{
	char *buffer = NULL, **args = NULL;
	int atty = 1;
	size_t buffer_size = 0;
	ssize_t input_byte;

	signal(SIGINT, signal_handler);
	env.p_name = argv[0];
	env.p_count = 0;
	while (atty && ac)
	{
		user_prompt(&atty);
		input_byte = get_line(&buffer, &buffer_size, stdin);
		if (input_byte == -1)
			getline_fail(environ, buffer);
		buffer[input_byte - 1] = '\0';
		if (*buffer == '\0')
		{
			free(buffer);
			continue;
		}
		args = split_buffer(buffer);
		free(buffer);
		buffer = NULL;
		if (args == NULL)
		{
			perror(argv[0]);
			exit(1);
		}
		handler(args, argv[0]);
		ffree(args);
		args = NULL;
	}
	if (env.flag)
		ffree(environ);
	ffree(args);
	return (0);
}

/**
*signal_handler - handles signal
*@signal: signal
*Return: void
*/

void signal_handler(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 *getline_fail - handles getline failure
 *@environ: environ variable
 *@buf: buffer variable
 *Return: void
 */

void getline_fail(char **environ, char *buf)
{
	if (env.flag)
		ffree(environ);
	write(STDOUT_FILENO, "\n", 1);
	free(buf);
	buf = NULL;
	exit(0);
}
