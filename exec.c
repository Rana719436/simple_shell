#include "shell.h"

/**
 * executeCommand - Executes a shell command.
 * @command: A null-terminated string containing the shell command.
 * @args: char argumants
 * Return:0 on success, -1 on failure.
 */

void executeCommand(char *command, char *args[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{

		char exec_path[] = "/usr/bin/";
		char full_path[MAX_INPUT_SIZE];

		strcpy(full_path, exec_path);
		strcat(full_path, command);

		execve(args[0], args, NULL);
		perror("./shell");
		free(command);
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
