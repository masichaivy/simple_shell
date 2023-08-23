#include "shell.h"

#define MAX_PATH_LEN 20

int path_finder(const char *cmd, char **user_cmd)
{
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	if (path == NULL)
	{
		printf("Error: PATH variable not found\n");
		return (0);
	}

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			user_cmd[0] = str_dup(cmd);
			return (1);
		}
		return (0);
	}

	while (dir != NULL)
	{
		char full_path[MAX_PATH_LEN];

		str_cpy(full_path, dir);
		str_cat(full_path, "/");
		str_cat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			user_cmd[0] = str_dup(full_path);
			free(path_copy);
			return (1);
		}

		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}

