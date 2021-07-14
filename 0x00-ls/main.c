#include "holberton.h"


/**
* main - main function
* @argc: aaa
* @argv: aaa
* Return: returns 0 when run correctly
*/
int main(int argc, char *argv[])
{
	int i;
	char *array = NULL;

	if (argc == 1)
	{
		array = bring_dir(".");
		printf("%s|\n", array);
		free(array);
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			if (dir_check(argv[i]) == 0)
			{
				fprintf(stderr, "./hls: cannot access%s: No suchfile or directory\n",
				 argv[i]);
				exit(2);
			}
			else
			{
				printf("%s:\n", argv[i]);
				array = bring_dir(argv[i]);
				printf("%s|\n", array);
				if (i != argc - 1)
					printf("\n");
				free(array);
			}
		}
	}
	return (0);
}

/**
* print_dir - fetch and prints a certain directorys content
* @path: pwd to directory
*/
char* bring_dir(char *path)
{
	struct dirent *read;
	DIR *dir;
	int count = 0, i;
	char *array2 = NULL;

	dir = opendir(path);
	while ((read = readdir(dir)) != NULL)
	{
		count = count + strlen(read->d_name);
		count++;
	}

	array2 = malloc(count + 1);
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
	array2[count] = '\0';
	closedir(dir);

	return (array2);
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
