#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

#include <string.h>
#include <sys/stat.h>


extern char **environ;

void print_env(void);
void handle_args(char *buffer, char *buffer_copy);
ssize_t get_line(char **buffer, size_t *buffer_size, FILE *stream);
void *re_alloc(void *ptr, unsigned int size, unsigned int new_size);
void add_lineptr(char **lineptr, size_t *l_size, char *buffer, size_t b_size);
void _exit(int status);
int set_env(const char *name, const char *value, int overwrite);
int unset_env(const char *name);
void exec_cmd(char *args[]);
void fork_exec(char *cmd, char *args[]);
char *path_finder(char *cmd);

int str_cmp(char *s1, char *s2);
char *str_cpy(char *dest, const char *src);
char *str_cat(char *dest, const char *src);
size_t str_len(const char *str);
char *str_dup(const char *src);

#endif
