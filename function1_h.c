#include "hshell.h"

/**
 *
 *@:
 *
 * Return:
 */
void array_analy(char *buf, char **env)
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

char *tokenizer(char *str, char *delim)
{
}

void fork()
{
}
