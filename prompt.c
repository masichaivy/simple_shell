#include "shell.h"

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
	int n, i;
	ssize_t len;
	char *cmd[];
	pid_t child_prcess

	n = 0;
	cmd = {NULL, NULL};
	while (1)
	{
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
		}

		child_prcess = fork();
		if (child_prcess == -1)
		{
			free(str);
			exit(EXIT_FAILURE);
		}
	}
}
