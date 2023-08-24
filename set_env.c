#include "shell.h"

/**
 * set_env - set environment variable.
 * @name: variable name.
 * @value: value.
 * @overwrite: 0 or 1
 *
 * Return: 0 on success,
 *	-1 on failure.
 */
int set_env(const char *name, const char *value, int overwrite)
{
	int i = 0, len = 0;
	char *new_env_nm;

	if (!name || !value)
		return (-1);
	new_env_nm = malloc(strlen(name) + strlen(value) + 2);
	strcpy(new_env_nm, name);
	strcat(new_env_nm, "=");
	strcat(new_env_nm, value);

	len = strlen(name);
	while (environ[i])
	{
		if (strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				environ[i] = new_env_nm;
			}
			return (0);
		}
		i++;
	}
	env[i] = new_env_nm;
	env[i + 1] = NULL;
	return (0);
}
