#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

void prompt(char **env);
void prt_error(char **str);
void fork_exec(char **user_cmd, char **env, char *str);
int str_cmp(char *s1, char *s2);
char *str_cpy(char *dest, const char *src);
char *str_cat(char *dest, const char *src);
size_t str_len(const char *str);
char *str_dup(const char *src);
int path_finder(const char *cmd, char **user_cmd);

#endif
