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
	char **wrd_array, *pth = NULL;
	int accss;
	int do_execv = 0;
	struct stat file_info;

	pth = found_pth(env);
	wrd_array = tokenizer(buf, " \t");
	if (wrd_array == NULL)
		perror("Error");
	else if ((strcmp(wrd_array[0], "exit")) == 0)
		exit_fx(wrd_array, buf);

	else if ((strcmp(wrd_array[0], "env")) == 0)
		prt_env(env);
	else if (wrd_array[0][0] != '/' && do_execv == 0)
	{
		do_execv = path_f(wrd_array, pth);
	}
	if (do_execv == 0)
	{
		if (stat(wrd_array[0], &file_info) == 0)
			do_execv = 1;
		else
			perror("Error");
	}

	if (do_execv == 1)
	{
		accss = access(wrd_array[0], X_OK);
		if (accss != 0)
			perror("Error");
		else
			forker(wrd_array, env);
	}
	_free(wrd_array);
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
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ' || str[i] == ':')
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
	{
		free(buf);
		return (NULL);
	}
	strcpy(buf, str);
	tkn = strtok(buf, delim);
	while (tkn != NULL)
	{
		wrd[i] = malloc((strlen(tkn) + 1) * sizeof(char));
		if (wrd[i] == NULL)
		{
			n = i;
			while (n >= 0)
			{
				free(wrd[n]);
				n--;
			}
			free(wrd);
			free(buf);
			return (NULL);
		}
		strncpy(wrd[i], tkn, strlen(tkn) + 1);
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

/**
 *prt_env - Prints the current environment
 *@env: Environment
 *
 * Return: void
 */
void prt_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env, strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
