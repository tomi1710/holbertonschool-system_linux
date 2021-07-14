#include "holberton.h"


/**
* main - main function
* Return: returns 0 when run correctly
*/
int main(void)
{
	char *array = NULL;

	array = bring_dir(".");
	printf("%s\n", array);
	free(array);

	return (0);
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
			count = count + strlen(read->d_name);
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
