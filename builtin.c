#include "shell.h"

/**
 * _myhelp - function changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * This function is a placeholder for a "help" command in the shell. It displays a message indicating
 * that the "help" command is called, but the actual functionality is not yet implemented.
 * It checks the 'info->argv' array for any arguments passed to the "help" command, but doesn't use them.
 * It returns 0.
 *
 * Return: Always 0.
 */
int _myhelp(info_t *info)

{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		/* temp att_unused workaround */
		_puts(*arg_array);
	return (0);
}

/**
 * _mycd - function changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * This function is responsible for changing the current directory of the shell process.
 * Return: Always 0.
 */

int _mycd(info_t *info)

{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			/* TODO: what should this be? */
			chdir_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		/* TODO: what should this be? */
		chdir_ret =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myexit - function exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * This function handles the "exit" command in the shell.
 * Return: If 'info->argv[0]' is "exit", it returns -2, otherwise it returns 0.
 */
int _myexit(info_t *info)

{
	int exitcheck;
	/* If there is an exit arguement */
	if (info->argv[1])
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
