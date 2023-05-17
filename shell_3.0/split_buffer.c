#include "shell.h"

/**
*split_buffer - Tokenizes string
*@buffer: string to split
*Return: pointer to the list of tokenized string
*/

char **split_buffer(char *buffer)
{
	char **list, *str, *buffcpy, delim[] = " :\n";
	int token_count, i = 0;

	buffcpy = _strdup(buffer);
	if (buffcpy == NULL)
		return (NULL);
	str = _strtok(buffcpy, delim);
	for (token_count = 0; str != NULL; token_count++)
		str = _strtok(NULL, delim);
	free(buffcpy);
	list = malloc(sizeof(char *) * (token_count + 1));
	if (list == NULL)
		return (NULL);
	str = _strtok(buffer, delim);
	while (str != NULL)
	{
		list[i] = _strdup(str);
		if (list[i] == NULL)
		{
			ffree(list);
			return (NULL);
		}
		str = _strtok(NULL, delim);
		i++;
	}
	list[i] = NULL;
	return (list);
}
