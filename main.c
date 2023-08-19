#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @env: environment vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int ac, char **env)
{
	if (ac == 1)
		prompt(env);

	return (0);
}
