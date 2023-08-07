#include "shell.h"

/**
 * bfree - Frees a pointer and sets it to NULL.
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if the pointer was freed, otherwise 0.
 *
 * Description: This function is used to safely free memory allocated for a
 * pointer and set the pointer to NULL. It takes a double pointer ptr as input
 * which represents the address of the pointer to be freed. The function first
 * checks if 'ptr' is not NULL and if the pointer it points to is not NULL.
 * If both conditions are true, it frees the memory pointed to by the pointer
 * using the free() function and then sets the pointer to NULL to avoid a
 * potential dangling pointer. Finally, the function returns 1 to indicate
 * that the memory was successfully freed and the pointer was set to NULL.
 * If 'ptr' or the pointer it points to is NULL, the function returns 0 to
 * indicate that no memory was freed, and the pointer remains unchanged.
 * This function provides a convenient and safe way to deallocate dynamically
 * allocated memory and avoids potential memory leaks and double-free issues.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
