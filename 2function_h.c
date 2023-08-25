#include "hshell.h"

/**
 *path_f - Checks for path
 *@str: Pointer to a string
 *@pth: Pointer to a string
 *
 * Return: integer 1 if successful
 */
size_t path_f(char **str, char *pth)
{
	int i = 0, Alength, Tlength;
	char **tkn;
	struct stat cmd;
	unsigned int n_sz, ol_sz;

	Alength = strlen(str[0]);
	tkn = tokenizer(pth, ":");

	while (tkn[i] != NULL)
	{
		ol_sz = strlen(tkn[i] + 1);
		Tlength = strlen(tkn[i]) + 2;
		n_sz = (Tlength + Alength) * sizeof(char);

		tkn[i] = reallocarray(tkn[i], ol_sz, n_sz);
		if (tkn[i] == NULL)
			return (0);

		strcat(tkn[i], "/");
		strcat(tkn[i], str[0]);

		if (stat(tkn[i], &cmd) == 0)
		{
			str[0] = reallocarray(str[0], Alength + 1, n_sz);
			if (str[0] == NULL)
				return(0);

			strcpy(str[0], tkn[i]);
			break;
		}

		i++;
	}

	_free(tkn);
	return (1);
}

/**
 *exit_fx - The shell exit fx
 *@str: Buffers to clear
 *@buf: Buffers to clear
 *
 * Return: void
 */
void exit_fx(char **str, char *buf)
{
	unsigned int exit_stat = 0;

	if (str[1] == NULL || strcmp(str[1], "0") == 0)
	{
		_free(str);
		free(buf);
		exit(0);
	}

	exit_stat = atoi(str[1]);

	if (exit_stat > 0)
	{
		_free(str);
		free(buf);
		exit(exit_stat);
	}

else
	{
		write(STDOUT_FILENO, "./hsh: 1: exit: Illegal number: ", 22);
		write(STDOUT_FILENO, str[1], strlen(str[1]));
		write(STDOUT_FILENO, "\n", 1);
		return;
	}
}

/**
 *_free- frees double pointers
 *@buf: Buffers to clear
 *
 * Return: void
 */
void _free(char **buf)
{
	char **holder;

	if (buf != NULL)
	{
		holder = buf;

		while (*buf)
			free(*buf++);

		free(holder);
	}
}

/**
 *found_pth - Checks for path in PATH
 *@env: environment array
 *
 * Return: Pointer to PATH
 */
char *found_pth(char **env)
{
	char *envg = NULL;
	int n = 0, cmp;

	while (env[n])
	{
		cmp = strncmp("PATH", env[n], 4);
		if (cmp == 0)
			envg = env[n] + 5;

		n++;
	}
	return (envg);
}
