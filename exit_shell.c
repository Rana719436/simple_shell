#include "shell.h"

void exit_shell(void)
{
	char input[100];

	while (1)
	{
		write(STDOUT_FILENO, "SimpleShell> ", 13);
		read(STDIN_FILENO, input, 100);
		input[strcspn(input, "\n")] = 0;

		if (strcmp(input, "exit") == 0)
		{
			exit(0);
		}
		else
	}
}

int main(void)
{
	void exit_shell(void);
}
