#include "holberton.h"

/**
* dir_check - function to check if directory exists.
* @dir_name: command or file name.
*
* Return: 1 on succes, 0 on failure.
*/
int dir_check(char *dir_name)
{
	DIR *dir = NULL;

	dir = opendir(dir_name);

	if (dir == NULL)
	{
		if (errno == 2)
		{
			fprintf(stderr, "./hls: cannot access %s: No such file or directory\n"
			, dir_name);
			closedir(dir);
			return (2);
		}
		else if (errno == 13)
		{
			fprintf(stderr, "./hls: cannot open directory %s: Permission denied\n"
			, dir_name);
			closedir(dir);
			return (2);
		}
	}
	closedir(dir);
	return (0);
}

/**
* dir_check2 - function to check if directory exists.
* @dir_name: command or file name.
*
* Return: 1 on succes, 0 on failure.
*/
int dir_check2(char *dir_name)
{
	DIR *dir = NULL;

	dir = opendir(dir_name);

	if (dir == NULL)
	{
		if (errno == 2)
		{
			closedir(dir);
			return (2);
		}
		else if (errno == 13)
		{
			closedir(dir);
			return (2);
		}
	}
	closedir(dir);
	return (0);
}
