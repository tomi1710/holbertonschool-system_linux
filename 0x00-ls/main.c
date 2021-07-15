#include "holberton.h"

/**
* main - main function
* @argc: asda
* @argv: asda
* Return: returns 0 when run correctly
*/
int main(int argc, char *argv[])
{
	int i, numero = 0, retoptions = 0, salto = 0, dirs_len = 0;
	int bandera_numero = 0;
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
		handle_options(retoptions, array);
	}
	else
		bandera_numero = else_main(numero, dirs, i, bandera_numero,
		salto, dirs_len, array, retoptions, options);

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
/**
* aux - returns an array with dirs
* @dirs: asdads
* @file_count1: asdadsad
* @file_count2: sadfs
* Return: returns array of dirs
*/
int aux(char **dirs, int file_count1, int file_count2)
{
	int i;

	for (i = 0; dirs[i] != '\0'; i++)
	{
		file_count1 = dir_check2(dirs[i]);
		if (file_count1 == -1)
			file_count2++;
	}
	if (file_count2 == 0)
		file_count2 = -1;

	return (file_count2);
}

int else_main(int numero, char **dirs, int i, int bandera_numero,
int salto, int dirs_len, char *array, int retoptions, char *options)
{
	int file_count1 = 0, file_count2 = 0;

	file_count2 = aux(dirs, file_count1, file_count2);
	for (i = 0; dirs[i] != '\0'; i++)
	{
		numero = dir_check2(dirs[i]);
		if (numero == 2)
			bandera_numero = numero;
		if (numero == 0)
		{
			if (salto != 0)
				printf("\n");
			else if (i == file_count2)
				printf("\n");
			salto++;
			if (dirs_len != 1)
				printf("%s:\n", dirs[i]);
			if (retoptions == 1)
			{
				aux_dos(array, dirs[i]);
			}
			else if (retoptions == 2)
			{
				aux_tres(array, dirs[i]);
			}
			else if (retoptions == 3)
			{
				array = bring_dir_A(dirs[i]);
				printf("%s\n", array);
			}
			else
			{
				aux_cuatro(array, dirs[i]);
			}
			salto++;
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
