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
* aux_dos - returns an array with dirs
* @array: asdads
* @dirs: asdadsad
* Return: returns array of dirs
*/
void aux_dos(char *array, char *dirs)
{
	array = bring_dir(dirs);
	print_uno(array);
}
/**
* aux_tres - returns an array with dirs
* @array: asdads
* @dirs: asdadsad
* Return: returns array of dirs
*/
void aux_tres(char *array, char *dirs)
{
	array = bring_dir_a(dirs);
	printf("%s\n", array);
}
/**
* aux_cuatro - returns an array with dirs
* @array: asdads
* @dirs: asdadsad
* Return: returns array of dirs
*/
void aux_cuatro(char *array, char *dirs)
{
	array = bring_dir(dirs);
	printf("%s\n", array);
}
