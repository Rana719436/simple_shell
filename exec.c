void executeCommand(char *command)
{
	pid_t child_pid = fork();

<<<<<<< HEAD
	if (child_pid == -1)
	{
		perror("fork");
	}
	else if (child_pid == 0)
	{
		char *args[] = {NULL, NULL};

		// Check if strdup() failed
		if (args[0] == NULL)
		{
			// Free the memory allocated to the command variable
			free(command);
			return;
		}

=======
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

>>>>>>> e438f4f449be4cc28bb46aaff36aff14cbd2143a
		args[0] = strdup(command);
		execve(args[0], args, NULL);
		perror("./shell");
		free(command);
<<<<<<< HEAD
		free(args[0]);
=======
>>>>>>> e438f4f449be4cc28bb46aaff36aff14cbd2143a
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

