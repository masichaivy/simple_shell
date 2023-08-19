#include "shell.h"

/**
 * fork_exec - executes child process
 *
 * @user_cmd: user command
 * @env: environment variable
 * @str: input string
 */

void fork_exec(char **user_cmd, char **env, char *str)
{
	pid_t child_prcess;
	int status;

	child_prcess = fork();
	if (child_prcess == -1)
	{
		prt_error(&str);
	}
	if (child_prcess == 0)
	{
		if (execve(user_cmd[0], user_cmd, env) == -1)
			printf("./shell: No such file or directory\n");
	}
	else
	{
		wait(&status);
	}
}
