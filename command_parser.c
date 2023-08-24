#include "shell.h"

/**
* is_cmd - determines if the file status is executable or not
* @info: attributes
* @path: direction to the file location
*
* Return: returns 1 if this is true and 0 if false
*/

int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
* dup_chars - this  copies the char
* @pathstr: the file PATH
* @start: initial index
* @stop: final index
*
* Return: this points  to a new memory region
*/

char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int h = 0, d = 0;

	for (d = 0, h = start; h < stop; h++)
		if (pathstr[h] != ':')
			buf[d++] = pathstr[h];
	buf[d] = 0;
	return (buf);
}

/**
* find_path - locates the cmd in the file PATH
* @info: the attributes
* @pathstr: the file PATH
* @cmd: the command to locate
*
* Return: resolved path of command if found or void
*/

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int q = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[q] || pathstr[q] == ':')
		{
			path = dup_chars(pathstr, curr_pos, q);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[q])
				break;
			curr_pos = q;
		}
		q++;
	}
	return (NULL);
}
