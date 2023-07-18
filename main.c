#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void display_prompt(void)
{
	printf("simple_shell$ ");
}

void execute_command(char *command)
{
	char *args[MAX_COMMAND_LENGTH];
	char *token;
	int i = 0;

	token = strtok(command, " \t\n");
	while (token != NULL)
	{
	args[i++] = token;
	token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;

	pid_t pid = fork();

	if (pid < 0)
	{
	perror("fork");
	exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
	execvp(args[0], args);
	perror("execvp");
	exit(EXIT_FAILURE);
	}

	else
	{

	int status;

	waitpid(pid, &status, 0);
	}
}

int main(void)
{
	char command_line[MAX_COMMAND_LENGTH];

	while (1)
	{
	display_prompt();

	if (fgets(command_line, sizeof(command_line), stdin) == NULL)
	{
	printf("\nExiting the shell...\n");
	break;
	}

	command_line[strcspn(command_line, "\n")] = '\0';

	execute_command(command_line);
	}

	return (0);
}
