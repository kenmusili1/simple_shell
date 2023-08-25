#include "hshell.h"

/**
 *plugin - Checks for inbuilt command
 *@arg: String of arguments
 *
 * Return: void
 */
short int plugin(char **arg)
{
	char **args = arg;
	short int plg_used = 0;

	if (strcmp(args[0], "cd") == 0)
	{
		ch_dir(args);
		plg_used = 1;
	}

	if (strcmp(args[0], "echo") == 0)
	{
		if (dollar_sit(args) == 1)
			_echo(args);
		plg_used = 1;
	}

	return (plg_used);
}
