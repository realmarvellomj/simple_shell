#include "shell.h"

/**
* **strtow - separatess a string into words. Repeat delimiters are ignored
* @str: writes the input strings
* @d: the delimeter or dividers string
* Return: this points to an array of strings, or returns null if it fails
*/

char **strtow(char *str, char *d)
{
	int k, l, m, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (k = 0; str[k] != '\0'; k++)
		if (!is_delim(str[k], d) && (is_delim(str[k + 1], d) || !str[k + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (k = 0, l = 0; l < numwords; l++)
	{
		while (is_delim(str[k], d))
			k++;
		m = 0;
		while (!is_delim(str[k + m], d) && str[k + m])
			m++;
		s[l] = malloc((m + 1) * sizeof(char));
		if (!s[l])
		{
			for (m = 0; m < l; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < m; n++)
			s[m][n] = str[k++];
		s[m][n] = 0;
	}
	s[l] = NULL;
	return (s);
}

/**
* **strtow2 - this divides a string into words
* @str: this is the source string
* @d: the delimeter string
* Return: this points to an array of strings, or return null if it fails
*/

char **strtow2(char *str, char d)
{
	int k, l, m, n, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (k = 0; str[k] != '\0'; k++)
		if ((str[k] != d && str[k + 1] == d) ||
		    (str[k] != d && !str[k + 1]) || str[k + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (k = 0, l = 0; l < numwords; l++)
	{
		while (str[k] == d && str[k] != d)
			k++;
		m = 0;
		while (str[k + m] != d && str[k + m] && str[k + m] != d)
			m++;
		s[l] = malloc((m + 1) * sizeof(char));
		if (!s[l])
		{
			for (m = 0; m < l; m++)
				free(s[m]);
			free(s);
			return (NULL);
		}
		for (n = 0; n < m; n++)
			s[l][n] = str[m++];
		s[l][n] = 0;
	}
	s[l] = NULL;
	return (s);
}

