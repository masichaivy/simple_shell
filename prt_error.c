#include "shell.h"

/**
 * prt_error - frees string on error
 * @str: string
 */

void prt_error(char **str)
{
	free(*str);
	exit(EXIT_FAILURE);
}
