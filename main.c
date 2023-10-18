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
<<<<<<< HEAD

		// Check if readCommand() failed
		if (command == NULL)
		{
			// Free the memory allocated to the command variable
			free(command);
			continue;
		}

=======
>>>>>>> e438f4f449be4cc28bb46aaff36aff14cbd2143a
		executeCommand(command);
		free(command);
	}
	return (0);
}

