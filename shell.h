#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt(char **env);
void prt_error(char **str);
void fork_exec(char **user_cmd, char **env, char *str);
int str_cmp(char *s1, char *s2);

#endif
