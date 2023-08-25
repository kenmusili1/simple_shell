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
 *@env: Pointer to the array holding Environment PATH
 *
 * Return: Always 0
 */
int main(int __attribute__((unused))argc, char **argv, char **env)
{
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
			input_analyzer(lineptr, env);
	}

	free(lineptr);
	return (0);
}

void end_null(char *str)
{
	short int j = 0;

	while (str[j])
	{
		if (str[j] == '\n')
			str[j] = '\0';
		j++;
	}
}
