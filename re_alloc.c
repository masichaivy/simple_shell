#include "shell.h"

/**
 * re_alloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @size: size of the allocated space for ptr.
 * @new_size: size for the new memory block.
 *
 * Return: ptr, if new_size == size.
 *         NULL, if new_size == 0 and ptr is not NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *re_alloc(void *ptr, unsigned int size, unsigned int new_size)
{
	void *m;
	char *new_ptr, *filler;
	unsigned int i = 0;

	if (new_size == size)
		return (ptr);

	if (!ptr)
	{
		m = malloc(new_size);
		if (!m)
			return (NULL);

		return (m);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = ptr;
	m = malloc(sizeof(*new_ptr) * new_size);
	if (!m)
	{
		free(ptr);
		return (NULL);
	}

	filler = m;

	while (i < size && i < new_size)
	{
		filler[i] = *new_ptr++;
		i++;
	}

	free(ptr);
	return (m);
}
