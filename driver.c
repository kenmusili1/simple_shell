#include "hshell.h"

/**
 *Filename: driver.c
 *main - Entry point 
 *@argc: Argument count
 *argv: Pointer to an array of arguments from the CL
 *env: Pointer to the array holding PATHS
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	ssize_t rd_ln;
	size_t n = 0;
	char *lineptr = NULL;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILEno, "$ ", 2);

		rd_ln = getline(&lineptr, &n, stdin);
		if (rd_ln == -1)
		{
			perror("Error");
			break;
		}

		fx();
	}

	free(lineptr);
	return (0);
}
