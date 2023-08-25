#ifndef _HSHELL_
#define _HSHELL_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <linux/limits.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

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

short int prt_env(char **env);

char *found_pth(char **env);

void end_null(char *str);

void ch_dir(char **str);

short int plugin(char **arg);

short int dollar_sit(char **str);

void _echo(char **command);

#endif /*_HSHELL_*/
