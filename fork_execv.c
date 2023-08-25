#include "shell.h"

/**
 * extra_fork_exec - Executes the command
 * @args: An array of user arguments
 * @argv: Array of command line arguments
 * @full_cmd: Full command
 * Return: Void
 */

int fork_execv(char **args, char **argv, char *full_cmd)
{
	pid_t pid_num;
	int status;

	pid_num = fork();
	if (pid_num < 0)
	{
		perror(full_cmd);
		exit(-1);
	}
	else if (pid_num == 0)
	{
		execve(full_cmd, args, environ);
		perror(argv[0]);
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
		errno = status;

		free(full_cmd);
		free(args);
	}
	return (status);
}

