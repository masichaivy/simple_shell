#include "shell.h"

/**
 * free_arr - Frees string array
 * @ac: Number to be freed
 * @argv: string array
 * Return: Void
 */

void free_arr(int ac, char *argv[])
{
	int i = 0;

	if (argv)
	{
		while (i < ac)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}
