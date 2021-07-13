#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

char** bring_array(char* path);
char** hsort(char **array);
int _strlen(char *s);
void printarr(char** array);
int strcicmp(char* a, char* b);

struct dirent *read;

int main(int argc, char *argv[])
{
    int i = 0;
    char** array = NULL;

    if (argc != 1)
    {
        argv = hsort(argv);
        for (i=1; i < argc; i++)
        {
            array = bring_array(argv[i]);
            if(argv[i][strlen(argv[i]) - 1] == '/')
            {
                argv[i][strlen(argv[i]) - 1] = '\0';
            }
            if (argc > 2)
                if (i > 1)
                    printf("\n");
                printf("%s/:\n", argv[i]);
            array = hsort(array);
            printarr(array);
        }
    }
    else
    {
        array = bring_array(".");
        array = hsort(array);
        printarr(array);
    }

    return (0);
}

char** hsort(char **array)
{
    int ordenado = 1, i, res;
    char* swap;

    while (ordenado != 0)
    {
        ordenado = 0;
        for (i=0; array[i + 1] != '\0'; i++)
        {
            res = strcicmp(array[i], array[i + 1]);
            if (res == 1)
            {
                ordenado++;
                swap = array[i];
                array[i] = array[i + 1];
                array[i + 1] = swap;
            }
        }
    }
    return (array);
}

int strcicmp(char* a, char* b)
{
    int sum = 0, i;

    for (i = 0; a[i] != '\0'; i++)
    {
        sum = tolower(a[i]) - tolower(b[i]);
        if (sum > 0)
        {
            return (1);
        }
        else if (sum < 0)
        {
            return (0);
        }
    }
    return (0);
}

char** bring_array(char* path)
{
    DIR *dir;
    unsigned int size = 0;
    int i = 0;
    char** array = NULL;


    dir = opendir(path);
    while ((read = readdir(dir)) != NULL)
        if (read->d_name[0] != '.')
            size++;

    array = malloc(size * sizeof(char *) + 1);
    if (array == NULL)
        exit(98);

    dir = opendir(path);
    while ((read = readdir(dir)) != NULL)
        if (read->d_name[0] != '.')
        {
            array[i] = read->d_name;
            i++;
        }
    array[i] = '\0';

    closedir(dir);

    return (array);
}

void printarr(char** array)
{
    int i = 0;

    for(i=0; array[i] != '\0'; i++)
        printf("%s  ", array[i]);
    printf("\n");
}