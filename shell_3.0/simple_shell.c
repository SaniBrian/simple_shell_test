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
	(void)ac;

	while (atty)
	{
		args = NULL;
		buffer = NULL;
		user_prompt(&atty);
		input_byte = getline(&buffer, &buffer_size, stdin);
		if (input_byte == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(buffer);
			break;
		}
		buffer[input_byte - 1] = '\0';
		if (*buffer == '\0')
		{
			free(buffer);
			continue;
		}
		args = split_buffer(buffer);
		free(buffer);
		if (args == NULL)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		handler(args, argv[0]);
		ffree(args);
	}
	ffree(args);
	return (0);
}
