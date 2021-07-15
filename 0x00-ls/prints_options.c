#include "holberton.h"

/**
* print_uno - prints with -1 option
* @array: array to print
*/
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
