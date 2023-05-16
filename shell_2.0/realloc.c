#include "shell.h"

/**
*_realloc - reallocates space for string array
*@list: list to reallocate space for
*Return: pointer to string array
*/

char **_realloc(char **list, size_t size, int count)
{
	char **tmp;
	int i = 0;

	if (list == NULL)
		return (NULL);
	tmp = list;
	list = malloc(size);
	if (list == NULL)
		return (NULL);
	while (i <= count)
	{
		list[i] = _strdup(tmp[i]);
		i++;
	}
	list[i] = NULL;
	ffree(tmp);
	return (list);
}
