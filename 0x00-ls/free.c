#include "holberton.h"

/**
* hfree - frees
* @dirs: to free
* @options: to free
*/
void hfree(char **dirs, char *options)
{
	int i;

	if (dirs)
		for (i = 0; dirs[i] != '\0'; i++)
		{
			free(dirs[i]);
		}
		free(dirs);
	if (options)
		free(options);
}
