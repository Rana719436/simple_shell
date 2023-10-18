#include "shell.h"

/**
 * parseArguments - execute acommand with arguments
 * @args: argument
 * @arg_count: argument count
 * @command: input
 * Return: void.
 */

void parseArguments(char *command, char *args[], int *arg_count)
{
	char *token = strtok(command, " ");

	*arg_count = 0;
	while (token != NULL && *arg_count < MAX_ARG_COUNT - 1)
	{
		args[*arg_count] = token;
		token = strtok(NULL, " ");
		(*arg_count)++;
	}
	args[*arg_count] = NULL;
}
