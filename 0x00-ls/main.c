#include "holberton.h"
#define MACRO "./hls: cannot access %s: No such file or directory\n"

/**
* main - main function
* @argc: asda
* @argv: asda
* Return: returns 0 when run correctly
*/
int main(int argc, char *argv[])
{
	int i, numero = 0, retoptions = 0, salto = 0, dirs_len = 0;
	char *array = NULL, *options = NULL, **dirs = NULL;

	options = option_finder(argc, argv);
	retoptions = chequear_opciones(options);
	dirs = dir_finder(argc, argv);

	if (dirs)
		for (i = 0; dirs[i] != '\0'; i++)
			dirs_len++;

	if (argc == 1 && options == NULL)
	{
		array = bring_dir(".");
		printf("%s\n", array);
		free(array);
	}
	else if (dirs == NULL && retoptions != 0)
	{
		array = bring_dir(".");
		if (retoptions == 1)
			print_uno(array);
		free(array);
	}
	else
	{
			for (i = 0; dirs[i] != '\0'; i++)
			{
				if (dir_check(dirs[i]) == 0)
				{
					if (salto != 0)
						printf("\n");
					if (dirs_len != 1)
						printf("%s:\n", dirs[i]);
					array = bring_dir(dirs[i]);
					if (retoptions == 1)
						print_uno(array);
					else
						printf("%s\n", array);
					salto++;
					free(array);
				}
			}
	}

	if (dirs)
		for (i = 0; dirs[i] != '\0'; i++)
			free(dirs[i]);
		free(dirs);
	if (options)
		free(options);
	return (numero);
}

/**
* dir_finder - returns an array with dirs
* @argc: asdads
* @argv: asdadsad
* Return: returns array of dirs
*/
char **dir_finder(int argc, char *argv[])
{
	int i, a, b = 0, count1 = 0, count2 = 1, contmalloc = 0;
	char **dirs = NULL;

	for (i = 0; i < argc; i++)
		if (argv[i][0] != '-' && argv[i][0] != '.' && argv[i][1] != '/')
			count1++;
	if (count1 != 0)
		dirs = malloc(count1 + 1);

	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] != '-' && argv[i][0] != '.' && argv[i][1] != '/')
		{
			for (a = 1; argv[i][a] != '\0'; a++)
				count2++;
			dirs[contmalloc] = malloc(count2 + 1);
			contmalloc++;
			count2 = 1;
		}
	}
	if (count1 != 0)
	{
		for (i = 0; i < argc; i++)
		{
			if (argv[i][0] != '-' && argv[i][0] != '.' && argv[i][1] != '/')
			{
				for (a = 0; argv[i][a] != '\0'; a++)
				{
					dirs[b][a] = argv[i][a];
				}
				dirs[b][a] = '\0';
				b++;
			}
		}
		dirs[b] = '\0';
	}

	return (dirs);
}

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
 * _strlen - fdfdf
 * @s: sksksks
 * Return: sassassass
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}

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
			fprintf(stderr, "./hls: cannot access '%s': No such file or directory\n"
			, dir_name);
		else if (errno == 13)
			fprintf(stderr, "Permission error");
		closedir(dir);
		return (2);
	}
	closedir(dir);
	return (0);
}
