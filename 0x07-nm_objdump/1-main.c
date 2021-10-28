#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Write a rogram that reproduces the GNU objdump command
 * @argc: argc
 * @argv: argv
 * @env: shell envirnment
 * Return: EXIT_FAILURE or EXIT_SUCCES
 */
int main(int argc, char **argv, char **env)
{
	char *av[] = {"./hobjdump", "-sf", "", NULL};

	(void)argc;
	av[2] = argv[1];
	if (execve("/usr/bin/objdump", av, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
