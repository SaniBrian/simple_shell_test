#include "shell.h"

/**
*split_buffer - Tokenizes string
*@buffer: string to split
*Return: pointer to the list of tokenized string
*/

char **split_buffer(char *buffer)
{
	char **list, **tmp, *str, *buffcpy, delim[] = " :\n";
	int i = 0;

	if (buffer == NULL)
		return (NULL);
	buffcpy = _strdup(buffer);
	if (buffcpy == NULL)
		return (NULL);
	list = malloc(sizeof(char *) * 1);
	if (list == NULL)
	{
		free(buffcpy);
		return (NULL);
	}
	str = _strtok(buffcpy, delim);
	while (str != NULL)
	{
		tmp = list;
		tmp[i] = _strdup(str);
		if (tmp[i] == NULL)
		{
			ffree(tmp);
			free(buffcpy);
			return (NULL);
		}
		list = _realloc(tmp, sizeof(char *) * (i + 2), i);
		if (list == NULL)
		{
			free(buffcpy);
			ffree(tmp);
			return (NULL);
		}
		str = _strtok(NULL, delim);
		i++;
	}
	free(buffcpy);
	free(buffer);
	return (list);
}
