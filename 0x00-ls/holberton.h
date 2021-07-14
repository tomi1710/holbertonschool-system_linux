#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

char **bring_array(char *path);
char **hsort(char **array);
int _strlen(char *s);
void printarr(char **array);
int strcicmp(char *a, char *b);
void freearr(char **array);

struct dirent *read;
#endif
