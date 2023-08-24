#include "shell.h"

/**
 * path_finder - gets the user full command if found.
 * @cmd: argument command.
 *
 * Return: the full command if found,
 *	Null if not found
*/
char *path_finder(char *cmd)
{
	char *path, *path_copy, *token, *full_cmd;
	struct stat st;

	path = getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		token = strtok(path_copy, ":");

		while (token)
		{
			full_cmd = malloc(strlen(cmd) + strlen(token) + 2);
			if (full_cmd == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}
			strcpy(full_cmd, token);
			strcat(full_cmd, "/");
			strcat(full_cmd, cmd);
			strcat(full_cmd, "\0");
			if (stat(full_cmd, &st) == 0)
			{
				free(path_copy);
				return (full_cmd);
			}
			else
			{
				free(full_cmd);
				token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}

