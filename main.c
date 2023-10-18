#include "shell.h"

/**
 * main - Prints a Simple shell
 * Return: Always 0
 */

int main(void)
{
	char *k;

	while (1)
	{
		printPrompt();
		k = readCommand();
		if (k == NULL)
		{
			break;
		}
		executeCommand(k);
		free(k);
	}
	return (0);
}
