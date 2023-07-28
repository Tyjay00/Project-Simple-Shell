#include "shell.h"

/**
 * _putchar - Writes the character 'c' to the standard output (stdout).
 * @c: The character to print.
 *
 * Return: On success, it returns 1.
 *         On error, it returns -1, and errno is set appropriately.
 *
 * Description: This function is used to print a single character to the standard
 * output. It uses a static buffer to store characters before actually writing
 * them to the output. When the buffer is full or when a special character
 * (BUF_FLUSH) is encountered, it writes the buffered characters to the output.
 * The BUF_FLUSH character is used to flush the buffer without printing any
 * additional character.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(1, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}

/**
 * _strcpy - Copies a string from source buffer to destination buffer.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: Pointer to the destination buffer.
 *
 * Description: This function copies the contents of the source buffer 'src'
 * to the destination buffer 'dest'. The function ensures that the destination
 * buffer is null-terminated after copying the string. It handles cases where
 * 'src' and 'dest' are the same or if 'src' is NULL.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	return (dest);
	while (src[i])
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _puts - Prints a null-terminated string to the standard output (stdout).
 * @str: The string to be printed.
 *
 * Return: Nothing.
 *
 * Description: This function prints the contents of the null-terminated string
 * 'str' to the standard output (stdout). If 'str' is NULL, the function does
 * nothing.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
	return;
	while (str[i] != '\0')
	{
	_putchar(str[i]);
	i++;
	}
}

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string.
 *
 * Description: This function duplicates a string 'str' by dynamically allocating
 * memory for a new string and copying the contents of 'str' into it. If 'str'
 * is NULL or if memory allocation fails, the function returns NULL. The caller
 * is responsible for freeing the memory allocated by this function when it is
 * no longer needed.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	return (NULL);
	while (*str++)
	length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	return (NULL);
	for (length++; length--;)
	ret[length] = *--str;
	return (ret);
}
