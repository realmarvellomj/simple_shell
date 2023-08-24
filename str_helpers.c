#include "shell.h"

/**
* _strcpy - this duplicates a string
* @dest: signifies the destination buffer
* @src: signifies the source buffer
*
* Return: returns the destination buffer
*/

char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
* _strdup - this copies the string
* @s: the string to be duplicated
*
* Return: returns pointer to the duplicated string
*/

char *_strdup(const char *s)
{
	int j = 0;
	char *ret;

	if (s == NULL)
		return (NULL);
	while (*s++)
		j++;
	ret = malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (NULL);
	for (j++; j--;)
		ret[j] = *--s;
	return (ret);
}

/**
*_puts - to display an input string
*@str: the string to be displayed
*
* Return: returns null
*/

void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
}

/**
* _putchar - puts the char ch to stdout
* @ch: the char to displayed
*
* Return: returns 1, if successful.
* if unsuccessful,return -1, then set errno appropriately.
*/

int _putchar(char ch)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buf[j++] = ch;
	return (1);
}

