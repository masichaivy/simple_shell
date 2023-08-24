#include "shell.h"
/**
 * fork_exec - uses fork to execute commands.
 * @cmd: command argument.
 * @args: arguments.
 *
 * Return: Nothing.
 */
void fork_exec(char *cmd, char *args[])
{
	char *full_cmd = NULL;
	int status;
	pid_t pid;

	full_cmd = get_command(cmd);
	if (full_cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(full_cmd, args, NULL) == -1)
			{
				perror("Error:");
				exit(0);
			}
		}
		else
			wait(&status);
	}
}

/**
 * exec_cmd - executes user commands.
 * @args: contains command and aruments.
 *
 * Return: Nothing.
 */

void exec_cmd(char *args[])
{
	char *cmd = NULL;

	if (args)
	{
		cmd = args[0];
		if (strcmp(cmd, "exit") == 0)
			exit(0);
		else if (strcmp(cmd, "env") == 0)
			printenv();
		else if (strcmp(cmd, "echo") == 0 && args[2])
		{
			if (strcmp(args[2], "|") == 0)
				printf("%s: 1: %s: not found\n", args[3], args[1]);
		}
		else if (strcmp(cmd, "setenv") == 0)
		{
			if (getenv(args[2]) && args[2])
				_setenv(args[1], args[2], 1);
			else
				_setenv(args[1], args[2], 0);
		}
		else if (strcmp(cmd, "unsetenv") == 0 && args[1])
		{
			if (args[1] && getenv(args[1]))
				_unsetenv(args[1]);
		}
		else
		{
			fork_exec(cmd, args);
		}
	}
}
