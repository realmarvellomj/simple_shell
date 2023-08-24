#include "shell.h"

/**
*_eputs - displays the user input
* @str: the strings to be displayed
*
* Return: returns void
*/

void _eputs(char *str)
{
	int m = 0;

	if (!str)
		return;
	while (str[m] != '\0')
	{
		_eputchar(str[m]);
		m++;
	}
}

/**
* _eputchar - outputss the char ch to stderr
* @ch: The char to be displayed
*
* Return: if it is successful, return 1.
* if unsuccessful, return -1, & set errno appropriately.
*/

int _eputchar(char ch)
{
	static int r;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(2, buf, r);
		r = 0;
	}
	if (ch != BUF_FLUSH)
		buf[r++] = ch;
	return (1);
}

/**
* _putfd - outputs the char ch to given fd
* @ch: The char to be displayed
* @fd: The file descriptor to print to
*
* Return: if successful, return 1.
* if unsuccessful, return  -1, then set errno appropriately.
*/

int _putfd(char ch, int fd)
{
	static int r;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || r >= WRITE_BUF_SIZE)
	{
		write(fd, buf, r);
		r = 0;
	}
	if (ch != BUF_FLUSH)
		buf[r++] = ch;
	return (1);
}

/**
*_putsfd - input string to be displayed
* @str: the text/string to be displayed
* @fd: the file descriptor to be used
*
* Return: returns the amount of chars inputed
*/

int _putsfd(char *str, int fd)
{
	int p = 0;

	if (!str)
		return (0);
	while (*str)
	{
		p += _putfd(*str++, fd);
	}
	return (p);
}

