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
		args[0] = command;
		args[1] = NULL;
		if (strcmp(args[0], "exit") == 0)
		{
			handleExit();
		}
		if (command == NULL)
		{
			break;
		}
		parseArguments(command, args, &arg_count);
		if (arg_count > 0)
		{
			char *command_path = findCommandPath(args[0]);

			if (command_path != NULL)
			{
				executeCommand(command_path, args);
				free(command_path);
			}
			else
			{
				executeCommand(args[0], args);
			}
		}
		free(command);
	}
	return (0);
}
