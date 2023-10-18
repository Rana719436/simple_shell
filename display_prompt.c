/**
 * printPrompt -  Reads a command from the user.
 * Return: void
 */

#include "shell.h"

void printPrompt()
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}
