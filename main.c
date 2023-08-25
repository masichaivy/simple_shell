#include "shell.h"

/**
 * runShell - runs the shell.
 * @buffer: line entered by the user.
 *
 * Return: Nothing.
 */
void runShell(char *buffer)
{
	char *buffer_copy = NULL;

	buffer_copy = malloc(sizeof(char) * strlen(buffer));
	if (buffer_copy == NULL)
	{
		perror("buffer_copy: malloc error");
		exit(1);
	}
	strcpy(buffer_copy, buffer);
	handle_args(buffer, buffer_copy);
	free(buffer_copy);
}
/**
 * main - main function.
 * @ac: arguments number.
 * @av: array of arguments.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *buffer = NULL;
	size_t buffer_size = 0;
	ssize_t n_char;

	(void)av;
	if (isatty(fileno(stdin)))
	{

	if (ac == 1)
		while (1)
		{
			write(1, "$ ", 2);
			n_char = get_line(&buffer, &buffer_size, stdin);
			if (n_char == -1)
			{
				printf("\n");
				return (-1);
			}
			if (strcmp(buffer, "\n") != 0)
			{
				runShell(buffer);
			}
		}
	}
	else
		while (get_line(&buffer, &buffer_size, stdin))
		{
			runShell(buffer);
			exit(0);
		}
	free(buffer);
	return (0);
}
