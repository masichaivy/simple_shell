#include "shell.h"


/**
 * fork_exec - Executes the command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * Return: Void
 */

int fork_exec(char **args, char **argv)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(argv[0]);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		errno = status;

		free(args);
	}

	return (status);
}

