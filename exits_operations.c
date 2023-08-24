#include "shell.h"

/**
**_strncpy -this duplicates the string
*@dest: where the duplicated string goes to
*@src: main source of the string
*@u: the number of chars to be duplicated
*Return: returns the joined string
*/

char *_strncpy(char *dest, char *src, int u)
{
	int o, p;
	char *s = dest;

	o = 0;
	while (src[o] != '\0' && o < u - 1)
	{
		dest[o] = src[o];
		o++;
	}
	if (o < u)
	{
		p = o;
		while (p < u)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (s);
}

/**
**_strncat - joins two strings together
*@dest: the initial string
*@src: the subsequent string
*@u: the number of bytes to be largely used
*Return: returns the joined string
*/

char *_strncat(char *dest, char *src, int u)
{
	int o, p;
	char *s = dest;

	o = 0;
	p = 0;
	while (dest[o] != '\0')
		o++;
	while (src[p] != '\0' && p < u)
	{
		dest[o] = src[p];
		o++;
		p++;
	}
	if (p < u)
		dest[o] = '\0';
	return (s);
}

/**
**_strchr - finds a char in a string
*@str: the string to be analysed
*@ch: the char to search for
*Return: (str) points to the memory area s
*/

char *_strchr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

