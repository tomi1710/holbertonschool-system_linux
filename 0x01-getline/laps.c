#include "laps.h"

static int **autos = NULL;
static unsigned int size_autos = 0, dif_size;

void race_state(int *id, size_t size)
{
	unsigned int i = 0, j = 0, count = 0;

	dif_size = 0;
	if (autos == NULL)
	{
		printf("primer if\n");
		_malloc(size);
		if (size_autos == 0)
			size_autos = size;
		for (i = 0; i < size_autos; i++)
		{
			autos[i][0] = id[j];
			j++;
		}
	}
	else
	{
		printf("primer else\n");
		for (i = 0; i < (size - 1); i++)
		{
			printf("for de i en else\n");
			count = 0;
			for (j = 0; j < (size_autos - 1); j++)
			{
				printf("for de j en else\n");
				printf("i = %i\nj = %i\n", i, j);
				if (id[i] == autos[j][0])
					count = 1;
			}
			if (count == 1)
			{
				size_autos++;
				dif_size++;
			}
		}
		if (size_autos == 0)
			size_autos = size;
		printf("antes de realloc\n");
		_realloc(id, size);
		printf("despues de realloc\n");
	}

	printf("antes de printear autos\n");
	for (i = 0; i < (size_autos); i++)
	{
		printf("%i - ", autos[i][0]);
		printf("%i\n", autos[i][1]);
	}
	printf("printee autos\n");
}

void _malloc(int size)
{
	int i = 0;

	printf("entre a _malloc\n");
	autos = malloc(size * sizeof(int));
	if (autos == NULL)
		exit(1);
	printf("hice primer malloc\n");
	for (i = 0; i < size; i++)
	{
		autos[i] = (int *)malloc(sizeof(int) * 2);
		autos[i][1] = 0;
		if (autos == NULL)
			exit(1);
	}
	printf("hice segundo malloc\n");
}

void _realloc(int *id, size_t size)
{
	unsigned int start = 0, new_size, i, j, count = 0;

	new_size = (size_autos * 4) + 4;

	autos = realloc(autos, new_size);

	start = new_size - dif_size;

	for (i = 0; i < size; i++)
	{
		count = 0;
		for (j = 0; j < size_autos; j++)
		{
			if (id[i] == autos[size_autos][0])
				count = 1;
		}
		if (count == 0)
		{
			autos[start][0] = id[i];
			start++;
		}
	}
	if (size_autos == 0)
		size_autos = size;
}