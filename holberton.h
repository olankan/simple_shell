#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#define LSH_RL_BUFSIZE 1024
#ifdef LSH_USE_STD_GETLINE

int _launch(char **args);
int lsh_cd(char **args);
int lsh_help(char *);
int lsh_exit(char *);
int lsh_num_builtins(void);
int _execute(char **args);
void sh_loop(void);
char **_split_linr(char *line);
#endif
#endif
