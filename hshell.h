#ifndef _HSHELL_
#define _HSHELL_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/**
 *input_analyzer - Checks the array and does the approprate action
 *@buf: A string of characters
 *@env: The env array
 *
 * Return: void
 */
void input_analyzer(char *buf, char **env);

int counter(char *str);

char **tokenizer(char *str, char *delim);

void forker(char **buf, char **env);

#endif /*_HSHELL_*/
