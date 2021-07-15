#include "holberton.h"
#define MACRO "./hls: cannot access %s: No such file or directory\n"
int dir_check2(char *dir_name);
/**
* main - main function
* @argc: asda
* @argv: asda
* Return: returns 0 when run correctly
*/
int main(int argc, char *argv[])
{
	int i, numero = 0, retoptions = 0, salto = 0, dirs_len = 0, bandera_numero = 0;
	char *array = NULL, *options = NULL, **dirs = NULL;

	options = option_finder(argc, argv);
	retoptions = chequear_opciones(options);
	dirs = dir_finder(argc, argv);

	if (dirs)
	{
		for (i = 0; dirs[i] != '\0'; i++)
		{
			dirs_len++;
		}
	}

	if (argc == 1 && options == NULL)
	{
		array = bring_dir(".");
		printf("%s\n", array);
		free(array);
	}
	else if (dirs == NULL && retoptions != 0)
	{
		if (retoptions == 1)
		{
			array = bring_dir(".");
			print_uno(array);
		}
		if (retoptions == 2)
		{
			array = bring_dir_a(".");
			printf("%s\n", array);
		}
		if (retoptions == 3)
		{
			array = bring_dir_A(".");
			printf("%s\n", array);
		}
		free(array);
	}
	else
	{
		for (i = 0; dirs[i] != '\0'; i++)
		{
			numero = dir_check2(dirs[i]);
			if (numero != 0)
				bandera_numero = numero; 
			if (numero == 0)
			{
				if (salto != 0)
					printf("\n");
				if (dirs_len != 1)
					printf("%s:\n", dirs[i]);
				if (retoptions == 1)
				{
					array = bring_dir(dirs[i]);
					print_uno(array);
				}
				else if (retoptions == 2)
				{
					array = bring_dir_a(dirs[i]);
					printf("%s\n", array);
				}
				else if (retoptions == 3)
				{
					array = bring_dir_A(dirs[i]);
					printf("%s\n", array);
				}
				else
				{
					array = bring_dir(dirs[i]);
					printf("%s\n", array);
				}
				salto++;
				free(array);
			}
		}
	}
	hfree(dirs, options);
	return (bandera_numero);
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
		{
			count1++;
			dir_check(argv[i]);
		}
	if (count1 != 0)
	{
		dirs = malloc(count1 * 16);

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
