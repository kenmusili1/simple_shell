#include "hshell.h"

/**
 *input_analyzer - Checks the array and does the approprate action
 *@:
 *
 * Return:
 */
void input_analyzer(char *buf, char **env)
{
	char **wrd_array;
	int accss;

	wrd_array = tokenizer(buf, " \t");
	if(wrd_array == NULL)
		perror("Error");

	accss = access(wrd_array);
	if (accss != 0)
		perror("Error");
	else
		forker(wrd_array, env);

	return (0);
}

/**
 *
 *@:
 *
 * Return:
 */
char **tokenizer(char *str, char *delim)
{
	int i = 0, n = 0, count = 0;
	char **wrd = NULL;
	char *tkn, *buf;

	buf = malloc((strlen(str) + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == ' ')
			continue
		else
		{
			count++;
			i++;
		}
	}

	wrd = malloc((count + 1) * sizeof(char *));
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
 *
 *@:
 *
 * Return:
 */
void fork()
{
}
