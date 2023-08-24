#include "shell.h"

/**
* _strlen - this returns size of a string
* @str: the string whose size is to be checked
*
* Return: returns the  integer length of string
*/

int _strlen(char *str)
{
	int w = 0;

	if (!str)
		return (0);

	while (*str++)
		w++;
	return (w);
}

/**
* _strcmp - this evaluates the lexicographic order of two strings.
* @str1: the initial string
* @str2: the subsequent string
*
* Return: if str1 > str2, return positive,
* return negative if str1 < str2,
* 0 if str1 == str2
*/

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
* starts_with - checks if needle starts with haystack
* @haystack: the source & string to search
* @needle: the substring to find in the source
*
* Return: returns the next char of haystack or nothing
*/

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - this joins two strings together
* @dest: this is the destination buffer
* @src: this is the source buffer
*
* Return: returns to the destination buffer
*/

char *_strcat(char *dest, char *src)
{
	char *ret = dest; /*stores the initial address of dest*/

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++; /*copies char from src to dest*/
	*dest = *src;
	return (ret);
}

