#include "shell.h"
/**
*_strtok - splits strings with delimiter
*@string: string to split
*@dlm: delimeter
*Return: splitted string
*/

char *_strtok(char *string, char *dlm)
{
	static char *str;
	int i, j;
	char *cpy;

	if (string != NULL)
		str = string;
	if (str == NULL || *str == '\0')
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		cpy = str;
		j = 0;
		while (dlm[j] != '\0')
		{
			if (str[i] == dlm[j])
			{
				if (i != 0)
				{
					str = &str[i + 1];
					cpy[i] = '\0';
					return (cpy);
				}
				str = &str[i + 1];
				j = 0;
				continue;
			}
			j++;
		}
	}
	cpy = str;
	str = &str[i];
	return (cpy);
}
