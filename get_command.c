#include "shell.h"

/**
 * readCommand - Reads a command from the user.
 * Return: void.
 */

char *readCommand(void)
{
	char *command = NULL;
	size_t command_len = 0;
	ssize_t bytes_read;

	bytes_read = getline(&command, &command_len, stdin);
	if (bytes_read == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}

		return (NULL);

	}
	if (bytes_read > 0 && command[bytes_read - 1] == '\n')
	{
		command[bytes_read - 1] = '\0';
	}
	return (command);

}
