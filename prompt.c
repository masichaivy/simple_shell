#include "shell.h"
#include <sys/wait.h>

#define MAX_INPUT_SIZE 10

void prompt_display(void);

/**
 * prompt - displays prompt
 * @av: arg vector
 * @env: environment variable
 *
 * Return: void
 */

void prompt(char **av, char **env)
{
	char *str = NULL;
	int i, j, status;
	size_t n = 0;
	ssize_t len;
	char *user_cmd[MAX_INPUT_SIZE];
	pid_t child_prcess;

	while (1)
	{
		prompt_display();
		len = getline(&str, &n, stdin);
		if (len == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = 0;
			i++;
		}
		j = 0;
		user_cmd[j] = strtok(str, " ");
		while (user_cmd[j] != NULL)
			user_cmd[++j] = strtok(NULL, " ");
		child_prcess = fork();
		if (child_prcess == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
		if (child_prcess == 0)
		{
			if (execve(user_cmd[0], user_cmd, env) == -1)
				printf("%s: No such file or directory\n", av[0]);
		}
		else
		{
			wait(&status);
		}
	}
}

/**
 * prompt_display - displays prompt *
 */

void prompt_display(void)
{
	if (isatty(STDIN_FILENO))
		printf("savi->$ ");
}
