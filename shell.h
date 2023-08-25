#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void prt_error(char *prog, int count, char *cmd);
void _puts(char *str);
int _putchar(char c);
void free_arr(int ac, char *argv[]);

extern char **environ;
int fork_exec(char **args, char **argv);
int fork_execv(char **args, char **argv, char *full_cmd);
char *get_full_path(char *paths, char *cmd);
char *path_finder(void);
void fix_comments(char *buffer);
int set_env(char **args, char *nme_prog, char *buffer);

char **tokenizah(char *string);

int str_cmp(char *s1, char *s2);
char *str_cpy(char *dest, const char *src);
char *str_cat(char *dest, const char *src);
size_t str_len(const char *str);
char *str_dup(const char *src);

#endif
