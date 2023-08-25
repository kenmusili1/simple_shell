#include "hshell.h"

/**
 *sig_handler - Handles ctr+c
 *
 *@sig: voided
 *
 * Return: void
 */
void _isignal(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 *main - Entry point
 *
 *@argc: Argument count
 *@argv: Pointer to an array of arguments from the CL
 *@env: Pointer to the array holding PATHS
 *
 * Return: Always 0
 */
int main(int __attribute__((unused))argc, char **argv, char **env)
{
	int i;
	ssize_t rd_ln = 1;
	size_t n = 0;
	char *lineptr = NULL;

	(void)argv;
	while (rd_ln > 0)
	{
		signal(SIGINT, _isignal);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);

		rd_ln = getline(&lineptr, &n, stdin);
		if (rd_ln == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (counter(lineptr) > 0)
		{	

			i = 0;
			while (lineptr[i])
			{
				if (lineptr[i] == '\n')
				{
					lineptr[i] = '\0';
					break;
				}
				
				i++;
			}

			input_analyzer(lineptr, env);
		}
	}

	free(lineptr);
	return (0);
}
