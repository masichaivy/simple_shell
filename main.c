#include "shell.h"

/**
 * main - main function.
 * @ac: arguments number.
 * @av: array of arguments.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *buffer = NULL, *buffer_copy = NULL;
	size_t buffer_size = 0;
	ssize_t n_char;

	(void)av;
	if (ac == 1)
		while (1)
		{
			write(1, "savi=>$ ", 2);
			n_char = _getline(&buffer, &buffer_size, stdin);
			if (n_char == -1)
			{
				printf("\n");
				return (-1);
			}
			buffer_copy = malloc(sizeof(char) * n_char);
			if (buffer_copy == NULL)
			{
				perror("buffer_copy: malloc error");
				return (-1);
			}
			strcpy(buffer_copy, buffer);
			handle_args(buffer, buffer_copy);

			free(buffer_copy);
		}
	free(buffer);
	return (0);
}

