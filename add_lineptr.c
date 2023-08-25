#include "shell.h"

/**
 * add_lineptr - Add the lineptr variable for get_line.
 * @lineptr: A buffer to store the input.
 * @l_size: The size of lineptr.
 * @buffer: The string to add to lineptr.
 * @b_size: The size of buffer.
 */
void add_lineptr(char **lineptr, size_t *l_size, char *buffer, size_t b_size)
{
	if (!*lineptr)
	{
		if (b_size > 120)
			*l_size = b_size;
		else
			*l_size = 120;
		*lineptr = buffer;
	}
	else if (*l_size < b_size)
	{
		*l_size = (b_size > 120) ? b_size : 120;
		*lineptr = buffer;
	}
	else
	{
		strcpy(*lineptr, buffer);
		free(buffer);
	}
}
