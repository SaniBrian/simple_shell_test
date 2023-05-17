#include "shell.h"
/**
*_strdup - returns a pointer to allocated space in memory
*@str: original string pointer
*Return: pointer to the allocated memory
*/
char *_strdup(char *str)
{
	char *a;
	int l, i;

	if (str == NULL)
		return (NULL);

	l = 0;
	while (str[l] != '\0')
		l++;

	a = malloc((sizeof(char) * l) + 1);
	if (a == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		a[i] = str[i];

	a[i] = '\0';
	return (a);
}
