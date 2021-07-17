#include "holberton.h"

/**
* main - main function
* @argc: asda
* @argv: asda
* Return: returns 0 when run correctly
*/
int main(int argc, char *argv[])
{
	int i, numero = 0, retoptions = 0, dirs_len = 0;
	int bandera_numero = 0, salto = 0, salto1 = 1;
	char *array = NULL, *options = NULL, **dirs = NULL;

	options = option_finder(argc, argv);
	retoptions = chequear_opciones(options);
	dirs = dir_finder(argc, argv);

	if (dirs)
	{
		for (i = 0; dirs[i] != '\0'; i++)
			dirs_len++;
	}
	if (argc == 1 && options == NULL)
	{
		array = bring_dir(".");
		printf("%s\n", array);
		free(array);
	}
	else if (dirs == NULL && retoptions != 0)
	{
		handle_options(retoptions, array);
	}
	else
	{
		for (i = 0; dirs[i] != '\0'; i++)
		{
			salto = dir_check2(dirs[i]);
			if (salto == -1)
				salto1 = 0;
		}
		if (salto1 == 0)
		{
			printf("\n");
			salto1++;
		}
		bandera_numero = else_main(numero, dirs, i, bandera_numero,
		dirs_len, array, retoptions, options);
	}
	return (bandera_numero);
}

/**
* handle_options - main function
* @retoptions: asda
* @array: asda
* Return: returns 0 when run correctly
*/
void handle_options(int retoptions, char *array)
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

int else_main(int numero, char **dirs, int i, int bandera_numero,
int dirs_len, char *array, int retoptions, char *options)
{
	for (i = 0; dirs[i] != '\0'; i++)
	{
		numero = dir_check2(dirs[i]);
		if (numero == 2)
			bandera_numero = numero;
		if (numero == 0)
		{
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
			free(array);
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
		if (argv[i][0] != '-' && argv[i][1] != '/')
		{
			count1++;
			dir_check(argv[i], argv[0]);
		}
	if (count1 != 0)
	{
		dirs = malloc(count1 * 16);

		for (i = 0; i < argc; i++)
		{
			if (argv[i][0] != '-' && argv[i][1] != '/')
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
			if (argv[i][0] != '-' && argv[i][1] != '/')
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
