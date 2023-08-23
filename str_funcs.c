#include "shell.h"

/**
 * str_cpy - copies string
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */

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

/**
 * str_cat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */

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

/**
 * str_len - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: length of string
 */

size_t str_len(const char *str)
{
	const char *ptr = str;

	while (*ptr)
		ptr++;
	return ((size_t)(ptr - str));
}

/**
 * str_dup - duplicates strings
 * @src: the source buffer
 *
 * Return: pointer to new buffer
 */

char *str_dup(const char *src)
{
	size_t len = str_len(src) + 1;
	char *new_str = (char *)malloc(len);

	if (new_str != NULL)
		str_cpy(new_str, src);

	return (new_str);
}
