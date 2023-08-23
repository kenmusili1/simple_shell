#include "hshell.h"

/**
 *exit_fx - The shell exit fx
 *@str: Buffers to clear
 *@buf: Buffers to clear
 *
 * Return: void
 */

void exit_fx(char **str, char *buf)
{
	exit_stat = atoi(str[1]);

	if (str[1] == NULL || exit_stat == 0)
	{
		_free(str);
		free(buf);
		exit(0);
	}

	if (exit_stat < 0)
	{
		write(STOUT_FILENO, "exit: Illegal number: ", 22);
		write(STOUT_FILENO, str[1], strlen(str[1]));
		write(STOUT_FILENO, "\n", 1);
	}

	else
	{
		_free(str);
		free(buf);
		exit(exit_stat);
	}
}

/**
 *_free- free double pointers
 *@buf: Buffers to clear
 *
 * Return: void
 */

void _free(char **buf)
{
	char **holder;

	holder = buf;

	if (buf != NULL)
	{
		while (*buf)
			free(*buf++)
		free(holder);
	}
}
