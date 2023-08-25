#include "shell.h"

/**
 * path_finder - Retrieves and duplicates the path
 * Return: A strings of the PATH Variable
 */

char *path_finder(void)
{
	int i;
	char *dup = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
			dup = strdup(environ[i]);
	}

	return (dup);
}
