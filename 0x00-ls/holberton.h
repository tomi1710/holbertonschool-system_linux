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
char *bring_dir_A(char *path);
char *option_finder(int argc, char *argv[]);
int _strlen(char *s);
int dir_check(char *dir_name, char *functionn);
void print_uno(char *array);
int chequear_opciones(char *options);
char **dir_finder(int argc, char *argv[]);
void hfree(char **dirs, char *options);
int dir_check2(char *dir_name);
int else_main(int numero, char **dirs, int i, int bandera_numero,
int salto, int dirs_len, char *array, int retoptions, char *options);
void handle_options(int retoptions, char *array);
char *second_part_bring_dir(char *path, char *array2);
int aux(char **dirs, int file_count1, int file_count2);
void aux_dos(char *array, char *dirs);
void aux_tres(char *array, char *dirs);
void aux_cuatro(char *array, char *dirs);
#endif
