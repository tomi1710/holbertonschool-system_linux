#include "laps.h"

static int **autos;
static unsigned int size_autos, dif_size;

/**
 * race_state - keeps track of the number of laps made by several cars in arace
 * @id: array of int representing the “identifier” of each car
 * @size: size of this array
 */
void race_state(int *id, size_t size)
{
	unsigned int i = 0, j = 0, count = 0;

	if (size == 0)
		_free();
	else
	{
		dif_size = 0;
		if (autos == NULL)
		{
			_malloc(size);
			if (size_autos == 0)
				size_autos = size;
			for (i = 0; i < size_autos; i++)
			{
				autos[i][0] = id[j];
				j++;
			}
		}
		else if (ya_esta(id, size) == 0)
			sum_lap(id, size);
		else
		{
			sum_lap(id, size);
			for (i = 0; i < size; i++)
			{
				count = 0;
				for (j = 0; j < size_autos; j++)
					if (id[i] == autos[j][0])
						count = 1;
				if (count == 0)
					dif_size++;
			}
			if (size_autos == 0)
				size_autos = size;
			_realloc(id, size);
		}
		printf("Race state:\n");
		for (i = 0; i < size_autos; i++)
		{
			printf("Car %i [%i laps]\n", autos[i][0], autos[i][1]);
		}
	}
}

/**
 * _malloc - mallocs when the array = NULL
 * @size: size of this array
 */
void _malloc(int size)
{
	int i = 0;

	autos = malloc((size) * sizeof(int *));
	if (autos == NULL)
		exit(1);
	for (i = 0; i < size; i++)
	{
		autos[i] = (int *)malloc(sizeof(int) * 2);
		autos[i][1] = 0;
		if (autos[i] == NULL)
			exit(1);
	}
}

/**
 * _realloc - reallocs the size of the malloc in order to include knew cars
 * @id: array of int representing the “identifier” of each car
 * @size: size of this array
 */
void _realloc(int *id, size_t size)
{
	unsigned int start = 0, new_size, i, j, count = 0, save = 0, guardar;
	size_t new_sizet = 0;

	guardar = size_autos;
	new_size = (size_autos * 8) + (dif_size * 8);
	new_sizet = (size_t)new_size;
	autos = realloc(autos, new_sizet);

	start = size_autos;
	save = autos[0][0];
	for (; start < (size_autos + dif_size); start++)
		autos[start] = malloc(16);
	autos[0][0] = save;
	for (i = 0; i < (size); i++)
	{
		count = 0;
		for (j = 0; j < size_autos; j++)
		{
			if (id[i] == autos[j][0])
			{
				count = 1;
			}
		}
		if (count == 0)
		{
			autos[guardar][0] = id[i];
			size_autos++;
			guardar++;
		}
	}

	if (size_autos == 0)
		size_autos = size;
}

/**
 * sum_lap - sums laps to the mai array
 * @id: array of int representing the “identifier” of each car
 * @size: size of this array
 */
void sum_lap(int *id, int size)
{
	unsigned int j;
	int i;

	for (i = 0; i < (size); i++)
	{
		for (j = 0; j < size_autos; j++)
		{
			if (id[i] == autos[j][0])
			{
				autos[j][1]++;
			}
		}
	}
}

/**
 * _free - frees
 */
void _free(void)
{
	unsigned int i;

	for (i = 0; i <= size_autos; i++)
		free(autos[i]);
	free(autos);
}

int ya_esta(int *id, int size)
{
	int i, esta = 0;
	unsigned int j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size_autos; j++)
		{
			if (id[i] == autos[j][0])
			{
				esta++;
			}
		}
	}
	if (esta == size)
		return (0);
	return (1);
}