#include "hshell.h"

/**
 *
 *@:
 *
 * Return:
 */
void no_printer1(unsigned int i)
{
	unsigned int j = i;

	if ((j / 10) > 0)
		no_printer1(j / 10);

	putchar((j % 10) + '0');
}

/**
 *
 *@:
 *
 * Return:
 */
/*void dollar_sit(char **str, int n)
{
}*/
