#include "shell.h"

/**
 * print_env - prints environment variables.
 *
 * Return: Nothing.
 */
void print_env(void)
{
	int i = 0;

	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
