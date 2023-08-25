#include "shell.h"

/**
 * print_env - prints environment variables.
 *
 * Return: Nothing.
 */
void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
