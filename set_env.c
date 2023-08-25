#include "shell.h"

int set_env(char **args, char *nme_prog, char *buffer)
{
	int executed = 0, idx = 0;

	(void)nme_prog;

	if (strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(buffer);
		exit(errno);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		while (environ[idx] != NULL)
		{
			write(1, environ[idx], strlen(environ[idx]));
			write(1, "\n", 1);

			idx++;
		}
		free(args);
		executed = 1;
	}

	return (executed);
}

