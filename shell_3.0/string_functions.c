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
