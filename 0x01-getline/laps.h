#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void race_state(int *id, size_t size);
void _malloc(int size);
void _realloc(int *id, size_t size);
void sum_lap(int *id, int size);
void _free(void);
int ya_esta(int *id, int size);

#endif
