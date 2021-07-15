#include "holberton.h"

/**
* chequear_opciones - checks which options
* @options: array of options to check
* Return: returns based on option
*/
int chequear_opciones(char *options)
{
	int i;

	if (options)
	{
		for (i = 0; options[i] != '\0'; i++)
		{
			if (options[i] == '1')
			{
				return (1);
			}
            if (options[i] == 'a')
			{
				return (2);
			}
            if (options[i] == 'A')
			{
				return (3);
            }
		}
	}
	return (0);
}

/**
* option_finder - main function
* @argc: asda
* @argv: asda
* Return: returns 0 when run correctly
*/
char *option_finder(int argc, char *argv[])
{
	int i, a, b = 0, count = 0;
	char *options = NULL;

	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			for (a = 1; argv[i][a] != '\0'; a++)
			{
				count++;
			}
		}
	}

	if (count != 0)
	{
		options = malloc(count + 1);
		for (i = 0; i < argc; i++)
		{
			if (argv[i][0] == '-')
			{
				for (a = 1; argv[i][a] != '\0'; a++)
				{
					options[b] = argv[i][a];
					b++;
				}
			}
		}
		options[b] = '\0';
	}

	return (options);
}
