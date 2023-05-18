#include "shell.h"

/**
*_strlen - get string length
*@str: string
*Return: strings length
*/
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
*append_path - concatenates paths
*@s1: tokenized path
*@s2: exe
*Return: concatenated paths or NULL
*/
char *append_path(char *s1, char *s2)
{
	char *buffer;
	int i = 0, j = 0;

	buffer = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 2));
	if (buffer == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	if (s1[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}
	while (s2[j] != '\0')
	{
		buffer[i] = s2[j];
		i++;
		j++;
	}
	buffer[i] = '\0';
	return (buffer);
}

/**
*compare_str - compares two string
*@s1: string 1
*@s2: string 2
*Return: 1 if s1 == s2, 0 if otherwise
*/

int compare_str(char *s1, char *s2)
{
	int i = 0;

	if (_strlen(s1) != _strlen(s2) || *s1 != *s2)
		return (0);

	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;

	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);

	return (0);
}
