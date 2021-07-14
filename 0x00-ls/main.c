#include "holberton.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: returns 0 when run correctly
 */
int main(int argc, char *argv[])
{
	int i = 0;
	char **array = NULL;

	if (argc != 1)
	{
		argv = hsort(argv);
		for (i = 1; i < argc; i++)
		{
			array = bring_array(argv[i]);
			if (argv[i][strlen(argv[i]) - 1] == '/')
			{
				argv[i][strlen(argv[i]) - 1] = '\0';
			}
			if (argc > 2)
				if (i > 1)
					printf("\n");
				printf("%s/:\n", argv[i]);
			array = hsort(array);
			printarr(array);
			freearr(array);
		}
	}
	else
	{
		array = bring_array(".");
		array = hsort(array);
		printarr(array);
		freearr(array);
	}

	return (0);
}

/**
 * bring_array - puts all the things that are in a specific directory
 * into an array
 * @path: pwd to a specific array
 * Return: returns the array
 */
char **bring_array(char *path)
{
	DIR *dir;
	unsigned int size = 0;
	int i = 0;
	char **array = NULL;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
			size++;

	array = malloc(size * sizeof(char *));

	if (array == NULL)
		exit(98);

	closedir(dir);
	
	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
		if (read->d_name[0] != '.')
		{
			array[i] = read->d_name;
			i++;
		}
	array[i] = '\0';

	closedir(dir);

	return (array);
}

/**
 * printarr - prints an array
 * @array: array to be printed
 */
void printarr(char **array)
{
	int i = 0;

	for (i = 0; array[i] != '\0'; i++)
		printf("%s  ", array[i]);
	printf("\n");
}

void freearr(char **array)
{
	free(array);
}