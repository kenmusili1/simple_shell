#ifndef _HSHELL_
#define _HSHELL_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

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

void exit_fx(char **str, char *buf);

void _free(char **buf);

size_t path_f(char **str, char *pth);

void prt_env(char **env);

char *found_pth(char **env);

#endif /*_HSHELL_*/
