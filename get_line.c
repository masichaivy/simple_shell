#include "shell.h"

/**
 * get_line - custom get line from user function.
 * @lineptr: poiter to poiter of the text entered.
 * @n: size of the line entered.
 * @stream: stream to read from.
 *
 * Return: number of characters on success,
 *	-1 on failure.
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t user_input;
	ssize_t n_char;
	char ch = 'x', *buffer;
	int fd;

	(user_input == 0) ? fflush(stream) : -1;
	user_input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (ch != '\n')
	{
		fd = read(STDIN_FILENO, &ch, 1);
		if (fd == -1 || (fd == 0 && user_input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (fd == 0 && user_input != 0)
		{
			user_input++;
			break;
		}

		if (user_input >= 120)
			buffer = re_alloc(buffer, user_input, user_input + 1);

		buffer[user_input] = ch;
		user_input++;
	}
	buffer[user_input] = '\0';

	add_lineptr(lineptr, n, buffer, user_input);

	n_char = user_input;
	if (fd != 0)
		user_input = 0;
	return (n_char);
}

