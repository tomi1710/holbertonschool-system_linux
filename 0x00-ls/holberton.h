#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

char *bring_dir(char *path);
char *bring_dir_a(char *path);
char *option_finder(int argc, char *argv[]);
int _strlen(char *s);
int dir_check(char *dir_name);
void print_uno(char *array);
int chequear_opciones(char *options);
char **dir_finder(int argc, char *argv[]);
void hfree(char **dirs, char *options);

#endif
