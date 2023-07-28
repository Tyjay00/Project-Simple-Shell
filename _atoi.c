#include "shell.h"

/**
 * interactive - function returns true if the shell is in interactive mode
 * @info: struct address
 *
 * This function checks if the shell is running in interactive mode. It uses the `isatty` function
 * to check if the standard input file descriptor (0) is associated with a terminal. If the shell
 * is running interactively, it returns 1; otherwise, it returns 0.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * _atoi - function converts a string to an integer
 * @s: the string to be converted
 *
 * This function takes a string as input and converts it to an integer.
 *
 * Return: The converted integer. If no numbers in the string, it returns 0.
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

/**
 * is_delim - function checks if a character is a delimiter
 * @c: the char to check
 * @delim: the delimiter string
 *
 * This function checks if a character is present in the delimiter string.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - function checks for an alphabetic character
 * @c: The character to input
 *
 * This function checks whether a given character is an alphabetic character (a-z or A-Z).
 * If the character is alphabetic, the function returns 1; otherwise, it returns 0.
 *
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
