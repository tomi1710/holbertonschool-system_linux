#include "holberton.h"

/**
 * hsort - sorts a bidimensional array by alphanumeric, case insensitive
 * @array: array to sort
 * Return: returns the array sorted
 */
char **hsort(char **array)
{
	int ordenado = 1, i, res;
	char *swap;

	while (ordenado != 0)
	{
		ordenado = 0;
		for (i = 0; array[i + 1] != '\0'; i++)
		{
			res = strcicmp(array[i], array[i + 1]);
			if (res == 1)
			{
				ordenado++;
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
			}
		}
	}
	return (array);
}

/**
 * strcicmp - compares two strings by alphanumeric, case insensitive
 * @a: array 1
 * @b: array 2
 * Return: returns 0 if arrays are in place, and 1 if they need to be chancged
 */
int strcicmp(char *a, char *b)
{
	int sum = 0, i;

	for (i = 0; a[i] != '\0'; i++)
	{
		sum = tolower(a[i]) - tolower(b[i]);
		if (sum > 0)
		{
			return (1);
		}
		else if (sum < 0)
		{
			return (0);
		}
	}
	return (0);
}
