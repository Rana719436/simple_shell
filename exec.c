#include "shell.h"

/**
 * executeCommand - Executes a shell command.
 * @command: A null-terminated string containing the shell command.
 * Return:0 on success, -1 on failure.
 */

void executeCommand(char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		char *args[] = {NULL, NULL};
		if (args[0] == NULL)
		{
			free(command);
			return;
		}

		args[0] = strdup(command);
		execve(args[0], args, NULL);
		perror("./shell");
		free(args[0]);
		exit(1);
	}
	else
	{
		int status;

		if (wait(&status) == -1)
		{
			perror("wait");
		}
	}
}

