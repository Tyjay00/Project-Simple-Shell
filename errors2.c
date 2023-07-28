#include "shell.h"

/**
 * remove_comments - function substitutes "0" for the first occurrence of "#"
 * @buf: address of the string to modify
 *
 * This function searches for the first occurrence of the character '#' in the string 'buf'.
 * If the '#' is found at the beginning of the string or after a space character, it replaces
 * it and all subsequent characters with the null terminator '\0', effectively removing the comment.
 *
 * Return: Always 0.
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

/**
 * convert_number - a converter function that mimics itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * This function converts the integer 'num' into a string representation using the specified 'base'.
 * The 'flags' argument can be used to specify whether the number should be treated as unsigned.
 * Returns: the string representation of the number.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_d - function outputs an integer decimal (base 10) number.
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * This function prints the integer 'input' in decimal (base 10) format to the specified 'fd'.
 * If 'fd' is STDERR_FILENO, it writes to the standard error stream (stderr) instead of the standard output.
 * Returns: the number of characters printed.
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * _erratoi - creates an integer from a string
 * @s: the string being transformed
 *
 * This function converts a string 's' into an integer. It returns the converted integer value.
 * If the string does not represent a valid integer or the value exceeds the range of an integer,
 * Returns -1 to indicate an error.
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: information struct for parameters and returns
 * @estr: string with the indicated error type
 *
 * This function prints an error message to the standard error stream (stderr) using the provided 'info'.
 * It prints the filename, line number, command, and the error message specified by 'estr'.
 * Return: 0 if no numbers in string, converted number otherwise -1 on error.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}
