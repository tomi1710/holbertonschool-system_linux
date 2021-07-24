#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void race_state(int *id, size_t size);
void _malloc(int size, int *id);
void _realloc(int *id, size_t size);
void sum_lap(int *id, int size);
void hsort(void);
int _strlen(char *s);

#endif
