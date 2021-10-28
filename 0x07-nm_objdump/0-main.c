#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Write a program that reproduces the GNU nm command
 * @argc: argc
 * @argv: argv
 * @env: shell environment
 * Return: EXIT_FAILURE or EXIT_SUCCES
 */
int main(int argc, char **argv, char **env)
{
	char *av[] = {"./hnm", "-p", "", NULL};

	(void)argc;
	av[2] = argv[1];
	if (execve("/usr/bin/nm", av, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
