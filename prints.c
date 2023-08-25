#include "shell.h"

/**
 * _puts - prints a given string
 * @str: String to be printed
 * Return: Void
 *
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
}

/**
 * _putchar - Prints character
 * @c: Character to be printed
 * Return: An integer
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}
