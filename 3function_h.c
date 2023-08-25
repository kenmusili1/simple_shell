#include "hshell.h"

/**
 *
 *@:
 *
 * Return:
 */
/*void no_printer1(unsigned int i)
{
	unsigned int j = i;

	if ((j / 10) > 0)
		no_printer1(j / 10);

	putchar((j % 10) + '0');
}*/

/**
 *
 *@:
 *
 * Return: 0 if $x command is succesful
 */
short int dollar_sit(char **str)
{
	/*char *pth;*/
	pid_t proc = 0;
	/*char h = '\n';*/
	
	if (str[1] == NULL)
		return (1);

	if (strncmp(str[1], "$?", 2) == 0)
	{
		/*no_prnter2(127);*/
		/*write(STDOUT_FILENO, &h, 1);*/
		printf("0\n");
		return (0);
	}

	else if (strncmp(str[1], "$$", 2) == 0)
	{
		proc = getppid();
/*		no_printer1(proc);*/
		printf("%d\n", proc);
/*		write(STDOUT_FILENO, &h, 1);*/
		return (0);
	}
/*
	else if (strncmp(str[1], "$PATH", 5))
	{
		pth = getenv("PATH");
		write(STDOUT_FILENO, pth, strlen(pth));
		write(STDOUT_FILENO, &h, 1);
		return (0);
	}*/

	return (1);
}
