#include "shell.h"

void exit_shell(int __attribute__((unused)) argc, char **argv __attribute__((unused)))
{
	if (argc > 1)
	{
		write(STDERR_FILENO, "Usage: exit\n", 11);
	       	exit(1);
	}
	exit(0);
}
