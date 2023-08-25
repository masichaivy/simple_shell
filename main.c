#include "shell.h"

/**
 * main - Simple shell entry point
 * @ac: Argument counter
 * @argv: Argument Vector
 * Return: Errno
 *
 */

int main(int ac, char **argv)
{

	int mode = isatty(0);
	char *buffer = NULL, cmdc, **args = NULL, *full_cmd = NULL;
	size_t buff_Size = 0;
	ssize_t num = 0;
	int count = 0, builtin_status = 0;
	errno = 0;

	(void)ac;
	while (1)
	{
		count++;
		if (mode == 1)
			write(1, "$ ", 2);

		num = getline(&buffer, &buff_Size, stdin);
		if (num == -1)
		{
			free(buffer);
			exit(errno);
		}
		fix_comments(buffer);
		args = tokenizah(buffer);
		if (args[0] == NULL)
		{
			free(args);
			continue;
		}

		if (access(args[0], X_OK) == -1)
		{
			builtin_status = set_env(args, argv[0], buffer);
			if (builtin_status == 1)
				continue;
			full_cmd = get_full_path(path_finder(), args[0]);
			if (full_cmd == NULL)
			{
				cmdc = (count + '0');
				prt_error(argv[0], cmdc, args[0]);
				free(args);
				errno = 127;
				continue;
			}
		fork_execv(args, argv, full_cmd);
			continue;
		}
		fork_exec(args, argv);
	}

	return (errno);
}

