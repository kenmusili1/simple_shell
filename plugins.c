#include "hshell.h"

/**
 *ch_dir - Changes directory
 *@str: Commands
 *
 * Return: void
 */
void ch_dir(char **str)
{
	char **strs = str;
	char pth[PATH_MAX];
	int ch_error = 0;

	if (strs[1] == NULL)
	{
		ch_error = chdir(getenv("HOME"));
		if (ch_error == -1)
		{
			perror("./hsh");
			return;
		}
	}

	else if (strcmp(strs[1], "-") == 0)
	{
		ch_error = chdir(getenv("OLDPWD"));
		if (ch_error == -1)
		{
			perror("./hsh");
			return;
		}
	}

	else
	{
		ch_error = chdir(strs[1]);
		if (ch_error == -1)
		{
			perror("./hsh");
			return;
		}
	}

	getcwd(pth, sizeof(pth));
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", pth, 1);
}
