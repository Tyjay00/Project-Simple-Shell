#include "shell.h"

/**
 * _realloc - Reallocates a block of memory with a new size.
 * @ptr: Pointer to the previous allocated block of memory.
 * @old_size: The size (in bytes) of the previous block.
 * @new_size: The desired new size (in bytes) for the reallocated block.
 *
 * Return: Pointer to the reallocated block of memory.

 * Description: This function takes a pointer 'ptr' to a previously allocated
 * block of memory, 'old_size' representing its size, and 'new_size' as the
 * desired new size for the reallocated block. It reallocated the memory block
 * to the new size using malloc and copies the contents from the old block to
 * the new block. If 'ptr' is NULL, it simply allocates a new block using malloc.
 * If 'new_size' is 0, it frees the old block and returns NULL.
 * The function ensures to copy the minimum of 'old_size' and 'new_size' bytes
 * from the old block to the new block to avoid potential out-of-bounds access.
 * It returns the pointer to the reallocated block on success or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * _memset - Fills a block of memory with a constant byte.
 * @s: Pointer to the memory area to be filled.
 * @b: The byte value to fill the memory with.
 * @n: The number of bytes to be filled.
 *
 * Return: Pointer to the memory area 's'.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Frees a string of strings (array of pointers to strings).
 * @pp: Pointer to the string of strings to be freed.
 *
 * Return: Void.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
