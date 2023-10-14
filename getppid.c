#include "simple_shell.h"

/**
 * _getppid - that prints the PID of the parent process
 * @format: Fixed argument
 * Return: 0
 */

void  getppid()
{
	pid_t ppid = getppid();
	char buffer[100];
	
	snprintf(buffer, sizeof(buffer), "%d", ppid);
	write(STDOUT_FILENO, buffer, strlen(buffer));
}

