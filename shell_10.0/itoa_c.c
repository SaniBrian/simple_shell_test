#include "shell.h"

/**
 *int_len - gets digit count
 *@num: number
 *Return: int
 */

int int_len(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	} else
	{
		num1 = num;
	}
	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}
	return (len);
}

/**
 *_itoa - converts number to a string
 *@num: number to convert
 *Return: string
 */

char *_itoa(int num)
{
	char *buf;
	int len = int_len(num);
	unsigned int num1;

	buf = malloc(sizeof(char) * (len + 1));
	if (buf == NULL)
		return (NULL);
	buf[len] = '\0';
	if (num < 0)
	{
		num1 = num * -1;
		buf[0] = '-';
	} else
	{
		num1 = num;
	}
	len--;
	do {
		buf[len] = (num1 % 10) + '0';
		num1 /= 10;
		len--;
	} while (num1 > 0);

	return (buf);
}
