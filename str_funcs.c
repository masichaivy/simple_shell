#include "shell.h"

char *str_cpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (original_dest);
}

char *str_cat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (original_dest);
}

size_t str_len(const char *str)
{
	const char *ptr = str;

	while (*ptr)
		ptr++;
	return ((size_t)(ptr - str));
}

char *str_dup(const char *src)
{
	size_t len = str_len(src) + 1;
	char *new_str = (char *)malloc(len);

	if (new_str != NULL)
		str_cpy(new_str, src);

	return (new_str);
}
