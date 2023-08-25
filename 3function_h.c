#include "hshell.h"

/**
 *dollar_sit - Checks for $x
 *@str: string
 *
 * Return: 0 if $x command is succesful
 */
short int dollar_sit(char **str)
{
	char *pth;
	pid_t proc = 0;

	if (str[1] == NULL)
		return (1);

	if (strncmp(str[1], "$?", 2) == 0)
	{
		printf("0\n");
		return (0);
	}

	else if (strncmp(str[1], "$$", 2) == 0)
	{
		proc = getppid();
		printf("%d\n", proc);
		return (0);
	}

	else if ((strncmp(str[1], "$PATH", 5) == 0))
	{
		pth = getenv("PATH");
		printf("%s\n", pth);
		return (0);
	}

	return (1);
}
