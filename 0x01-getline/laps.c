#include "laps.h"

static int **autos = NULL;
static int size_autos = 0, dif_size;

void race_state(int *id, size_t size)
{
	int i = 0, j = 0, count = 0;

	dif_size = 0;
	if (autos == NULL)
	{
		_malloc(size);
		for (i = 0; i < size_autos; i++)
		{
			for (j = 0; j < size; j++)
			{
				autos[i] = id[j];
			}
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			count = 0;
			for (j = 0; j < size_autos; j++)
			{
				if (id[i] == autos[size_autos])
					count = 1;
			}
			if (count == 1)
			{
				size_autos++;
				dif_size++;
			}
		}
		for (size_autos == 0)
			size_autos = size;
	}

	for (i = 0; i < size_autos; i++)
		printf("%i\n", autos[size_autos]);
	printf("%i\n"autos);
}

void _malloc(int size)
{
	int i = 0;

	autos = malloc(size * sizeof(int));
	if (autos == NULL)
		exit(1);
	for (i = 0; i < size; i++)
	{
		autos[i] = malloc(sizeof(int));
		autos[i][1] = 0;
		if (autos == NULL)
			exit(1);
	}
}

void _realloc()
{
	int i = 0, new_size;

	new_size = (size_autos * 4) + 4;

	autos = realloc(autos, new_size);

	start = new_size - dif_size;
	for (; start < new_size)
		autos[start] = malloc(sizeof(int));
}