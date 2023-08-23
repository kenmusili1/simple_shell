#include "hshell.h"

/**
 *input_analyzer - Checks the array and does the approprate action
 *@buf: A string of characters
 *@env: The env array
 *
 * Return: void
 */
void input_analyzer(char *buf, char **env)
{
	char **wrd_array;
	int accss;

	wrd_array = tokenizer(buf, " \t");
	if (wrd_array == NULL)
		perror("Error");

	accss = access(wrd_array[0], X_OK);
	if (accss != 0)
		perror("Error");
	else
		forker(wrd_array, env);
}

/**
 *counter - Counts bytes of a string
 *@str: An array of string
 *
 * Return: Number of bytes of a string
 */
int counter(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			continue;
		else
			i++;
	}
	return (i);
}

/**
 *tokenizer - Splits string into tokens
 *@str: An array of string
 *@delim: Delimiter to split string
 *
 * Return: Pointer to array of the created tokens
 */
char **tokenizer(char *str, char *delim)
{
	int i = 0, n = 0;
	char **wrd = NULL;
	char *tkn, *buf;

	buf = malloc((strlen(str) + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);

	wrd = malloc((counter(str) + 1) * sizeof(char *));
	if (wrd == NULL)
		return (NULL);

	strcpy(buf, str);
	tkn = strtok(buf, delim);

	while (tkn)
	{
		wrd[i] = malloc((strlen(tkn) + 1) * sizeof(char));
		if (wrd == NULL)
		{
			n = i;

			while (n >= 0)
			{
				free(wrd[n]);
				n--;
			}

			free(wrd);
			return (NULL);
		}

		strcpy(wrd[i], tkn);
		tkn = strtok(NULL, delim);
		i++;
	}

	wrd[i] = NULL;
	free(buf);
	return (wrd);
}

/**
 *forker - Runs the command under a new child process
 *@buf: Commands passed
 *@env: Environment
 *
 * Return: void
 */
void forker(char **buf, char **env)
{
	int status;
	pid_t proc = fork();

	if (proc == -1)
		perror("Error");

	else if (proc > 0) /*Parent*/
	{
		do
			wait(&status);
		while
			(WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}

	else if	(proc == 0) /*Child*/
		execve(buf[0], buf, env);
}
