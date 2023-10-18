#include "shell.h"

/**
 * main - Prints a Simple shell
 * Return: Always 0
 */

int main(void)
{
	char *command;
	char *args[MAX_ARG_COUNT];
	int arg_count = 0;

	while (1)
	{
		printPrompt();
		command = readCommand();
		if (command == NULL)
		{
			break;
		}
		parseArguments(command, args, &arg_count);
		if (arg_count > 0)
		{
		executeCommand(args[0], args);
		}
		free(command);
	}
	return (0);
}
