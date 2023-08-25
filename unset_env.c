#include "shell.h"

/**
 * unset_env - remove an environment variable.
 * @name: Name of the environment variable to remove.
 *
 * Return: 0 if successful or -1 if unsuccessful.
 */
int unset_env(const char *name)
{
	char **temp_env;
	int i = 0, len = 0;

	len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			temp_env = environ;
			free(temp_env[i]);
			do {
				temp_env[i] = temp_env[i + 1];
				temp_env++;
			} while (*temp_env);
			return (0);
		}
		i++;
	}

	return (0);
}
