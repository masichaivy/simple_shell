#include "shell.h"

#define MAX_INPUT_SIZE 10

void prompt_display(void);

/**
 * prompt - displays prompt
 * @env: environment variable
 *
 * Return: void
 */

void prompt(char **env)
{
	char *str = NULL;
	int i, j;
	size_t n = 0;
	ssize_t len;
	char *user_cmd[MAX_INPUT_SIZE];

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
		if (str_cmp("exit", user_cmd[0]) == 0)
			break;
		fork_exec(user_cmd, env, str);
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
