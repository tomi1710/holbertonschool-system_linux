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
	int i, numero = 0, argx = 0, pos = 0;
	char *array = NULL, *options = NULL;

	options = option_finder(argc, argv);

	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] != '-')
			argx = argx + 1;
			if (pos == 0)
				pos = i;
	}	

	if (argx == 1 && options == NULL)
	{
		array = bring_dir(".");
		printf("%s\n", array);
		free(array);
	}
	else if (argx < 3 && chequear_opciones(options) == 1)
	{
		if (argx == 1)
			array = bring_dir(".");
		else
			array = bring_dir(argv[pos]);
		print_uno(array);
		free(array);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] != '-')
			{
				if (dir_check(argv[i]) == 0)
				{
					fprintf(stderr, MACRO, argv[i]);
					exit(2);
				}
				else
				{
					if (chequear_opciones(options) == 1)
					{
						printf("%s:\n", argv[i]);
						array = bring_dir(argv[i]);
						print_uno(array);
						if (i != argc - 1 && argv[argc - 1][0] != '-')
							printf("\n");
						free(array);
					}
					else
					{
						array = bring_dir(argv[i]);
						printf("%s:\n", argv[i]);
						printf("%s", array);
						printf("\n");
						if (i != argc - 1)
							printf("\n");
						free(array);
					}
				}
			}
		}
	}

	if (options)
		free(options);
	return (numero);
}

void print_uno(char *array)
{
	int i;

	for (i = 0; array[i] != '\0'; i++)
	{
		if (array[i] == ' ')
			array[i] = '\n';
	}
	printf("%s\n", array);
}

int chequear_opciones(char *options)
{
	int i;

	for (i = 0; options[i] != '\0'; i++)
	{
		if (options[i] == '1')
		{
			return (1);
		}
	}
	return (0);
}
/**
* option_finder - main function
* @argc: asda
* @argv: asda
* Return: returns 0 when run correctly
*/
char *option_finder(int argc, char *argv[])
{
	int i, a, b = 0, count = 0;
	char *options = NULL;

	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			for (a = 1; argv[i][a] != '\0'; a++)
			{
				count++;
			}
		}
	}

	if (count != 0)
	{
		options = malloc(count + 1);
		for (i = 0; i < argc; i++)
		{
			if (argv[i][0] == '-')
			{
				for (a = 1; argv[i][a] != '\0'; a++)
				{
					options[b] = argv[i][a];
					b++;
				}
			}
		}
		options[b] = '\0';
	}

	return (options);
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
	if (dir)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}
