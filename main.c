#include "shell.h"

/**
 * main - Prints a Simple shell
 * Return: Always 0
 */

int main(void)
{
	char *command;

	while (1)
	{
		printPrompt();
		command = readCommand();
		if (command == NULL)
		{
			break;
		}
		executeCommand(command);
		free(command);
	}
	return (0);
}
