#include "shell.h"

/**
 * _putfd - function writes character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * This function writes a character 'c' to the file descriptor 'fd'. It uses a static buffer
 * of size WRITE_BUF_SIZE to efficiently store and flush characters to the file descriptor.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputchar - function writes character c to stderr
 * @c: The character to print
 *
 * This function is similar to _putfd, but it specifically writes the character 'c' to the
 * standard error stream (stderr) instead of a general file descriptor.
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);

}

/**
 * _eputs - function prints an input string to stderr
 * @str: The string to be printed
 *
 * This function prints the input string 'str' to the standard error stream (stderr).
 * It uses the _eputchar function to print each character in the string.
 * If 'str' is NULL, the function does nothing and returns immediately.
 *
 * Return: Nothing.
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putsfd - function prints an input string.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * This function prints the input string 'str' to the specified file descriptor 'fd'.
 *
 * Return: The number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
