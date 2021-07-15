#include "holberton.h"

/**
* bring_dir - fetch and prints a certain directorys content
* @path: pwd to directory
* Return: x
*/
char *bring_dir(char *path)
{
	struct dirent *read;
	DIR *dir;
	int count = 0, i;
	char *array2 = NULL;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.')
		{
			count = count + _strlen(read->d_name);
			count++;
		}
	}

	array2 = malloc(count);

	closedir(dir);

	count = 0;
	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.')
		{
			for (i = 0; read->d_name[i] != '\0'; i++, count++)
				array2[count] = read->d_name[i];
			array2[count] = ' ';
			count++;
		}
	}
	array2[count - 1] = '\0';
	closedir(dir);

	return (array2);
}

/**
* bring_dir_a - fetch and prints a certain directorys content
* @path: pwd to directory
* Return: x
*/
char *bring_dir_a(char *path)
{
	struct dirent *read;
	DIR *dir;
	int count = 0, i;
	char *array2 = NULL;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		count = count + _strlen(read->d_name);
		count++;
	}

	array2 = malloc(count);

	closedir(dir);

	count = 0;
	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		for (i = 0; read->d_name[i] != '\0'; i++, count++)
			array2[count] = read->d_name[i];
		array2[count] = ' ';
		count++;
	}
	array2[count - 1] = '\0';
	closedir(dir);

	return (array2);
}

/**
* bring_dir_A - fetch and prints a certain directorys content
* @path: pwd to directory
* Return: x
*/
char *bring_dir_A(char *path)
{
	struct dirent *read;
	DIR *dir;
	int count = 0;
	char *array2 = NULL;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		if (_strlen(read->d_name) == 1)
		{
			if (read->d_name[0] != '.')
			{
				count = count + _strlen(read->d_name);
				count++;
			}
		}
		else if (_strlen(read->d_name) == 2)
		{
			if (read->d_name[0] != '.' && read->d_name[1] != '.')
			{
				count = count + _strlen(read->d_name);
				count++;
			}
		}
		else
		{
			count = count + _strlen(read->d_name);
			count++;
		}
	}

	array2 = malloc(count);

	closedir(dir);

	array2 = second_part_bring_dir(path, array2);
	return (array2);
}

/**
* second_part_bring_dir - fetch and prints a certain directorys content
* @path: pwd to directory
* @array2: pwd to directory
* Return: x
*/
char *second_part_bring_dir(char *path, char *array2)
{
	struct dirent *read;
	DIR *dir;
	int count = 0, i = 0;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		if (_strlen(read->d_name) == 1)
		{
			if (read->d_name[0] != '.')
			{
				for (i = 0; read->d_name[i] != '\0'; i++, count++)
					array2[count] = read->d_name[i];
				array2[count] = ' ';
				count++;
			}
		}
		else if (_strlen(read->d_name) == 2)
		{
			if (read->d_name[0] != '.' && read->d_name[1] != '.')
			{
				for (i = 0; read->d_name[i] != '\0'; i++, count++)
					array2[count] = read->d_name[i];
				array2[count] = ' ';
				count++;
			}
		}
		else
		{
			for (i = 0; read->d_name[i] != '\0'; i++, count++)
				array2[count] = read->d_name[i];
			array2[count] = ' ';
			count++;
		}
	}
	array2[count - 1] = '\0';
	closedir(dir);

	return (array2);
}
