#include "hshell.h"

/**
 *path_f - Checks for path
 *@str: Pointer to a string
 *@pth: Pointer to a string
 *
 * Return: integer 1 if successful
 */
int path_f(char **str, char *pth)
{
	int i = 0, Alength, Tlength, st_t;
	char **tkn;
	struct stat cmd;
	unsigned int n_sz, ol_sz;

	tkn = tokenizer(pth, ":");
	Alength = strlen(str[0]);

	while (tkn[i])
	{
		Tlength = (strlen(tkn[i]) + 2);
		n_sz = ((Tlength + Alength) * sizeof(char));
		ol_sz = (strlen(tkn[i] + 1));

		tkn[i] = reallocarray(tkn[i], ol_sz, n_sz);
		if (tkn == NULL)
			return (0);

		strcat(tkn[i], "/");
		strcat(tkn[i], str[0]);

		st_t = stat(tkn[i], &cmd);

		if (st_t == 0)
		{
			str[0] = reallocarray(tkn[0], Alength + 1, n_sz);
			if (tkn[0] == NULL)
				return (0);

			strcpy(str[0], tkn[i]);
			_free(tkn);
			return (1);
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
		write(STDOUT_FILENO, "exit: Illegal number: ", 22);
		write(STDOUT_FILENO, str[1], strlen(str[1]));
		write(STDOUT_FILENO, "\n", 1);
		return;
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
	if (buf != NULL)
	{
		while (*buf)
			free(*buf++);
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
	int i = 0;
	char *envg = NULL;

	while (env[i])
	{
		if (strncmp("PATH", env[i], 4) == 0)
			envg = env[i] + 5;

		i++;
	}
	return (envg);
}
