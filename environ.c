#include "shell.h"

/**
 * populate_env_list - fills in the env linked list
 * @info: Containing a potential argument structure. Used to maintain
 *        constant function prototype.
 *
 * This function populates the 'env' linked list in the 'info' structure with the environment variables
 * from the 'environ' array, which is an external array containing the environment variables.
 * It creates a new list node for each environment variable and adds it to the end of the list.
 *
 * Return: Always 0.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function is used to unset or remove an environment variable. It takes the environment variable
 * names as arguments in the 'info->argv' array. For each variable name, it calls the '_unsetenv' function
 * to remove it from the 'env' linked list.
 *
 * Return: Always 0.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function is used to set or modify an environment variable. It takes two arguments in the
 * 'info->argv' array - the name of the environment variable and its value. It calls the '_setenv'
 * function to create a new environment variable or modify an existing one in the 'env' linked list.
 *
 * Return: Always 0.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @name: env var name
 *
 * This function searches for the value of the environment variable with the specified 'name'
 * in the 'env' linked list of the 'info' structure. If the variable is found, it returns
 * a pointer to its value; otherwise, it returns NULL.
 * Return: the value.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * This function prints all the environment variables from the 'env' linked list in the 'info' structure.
 * It calls the 'print_list_str' function to print the 'str' field of each node in the list, which
 * corresponds to the environment variable.
 *
 * Return: Always 0.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
