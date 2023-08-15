#include "shell.h"
#include <sys/wait.h>

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
	int i, status;
	size_t n;
	ssize_t len;
	char *user_cmd[] = {NULL, NULL};
	pid_t child_prcess;

	n = 0;
	while (1)
	{
		if(isatty(STDIN_FILENO))
			printf("savi->$ ");

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
		user_cmd[0] = str;

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
