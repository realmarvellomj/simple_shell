#include "shell.h"

/**
* interactive - if it is interactive, return true
* @info: address of structure variable
*
* Return: if it's in interactive mode, return 1,else return 0
*/

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - verifies if char is a delimeter
* @ch: the char to check
* @d: the delimeter string
* Return: returns 1 if true & 0 if false
*/

int is_delim(char ch, char *d)
{
	while (*d)
		if (*d++ == ch)
			return (1);
	return (0);
}

/**
*_isalpha - checks if the charr is alphabetic
*@ch: the char to be inputed
*Return: return 1 if ch is an  alphabet & 0 if otherwise
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
*_atoi - this func  changes a str to an int
*@str: the string to be converted
*Return: return 0 if there is no char in string, converted number otherwise
*/

int _atoi(char *s)
{
	int v, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (v = 0;  s[v] != '\0' && flag != 2; v++)
	{
		if (s[v] == '-')
			sign *= -1;

		if (s[v] >= '0' && s[v] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[v] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

