#include "simple_shell.h"
void display_pro();

/**
 * display_pro - Prints a new prompt 
 * @display: signal.
 */

void display_pro()
{
	char pro[] = "#cisfun$";
	write(STDOUT_FILENO, pro, sizeof(pro) - 1);
}

int main() 
{
	while (1) 
	{
		display_pro();
		char *command = NULL;
		size_t l = 0;
		
		ssize_t i = getline(&command, &l, stdin);
		
		if (i == -1)
		{
			char newline = '\n';
			write(STDOUT_FILENO, &newline, 1);
			free(command);
			break;
		}

		int len = strlen(command);
		if (command[len-1] == '\n')
		{
			command[len-1] = '\0';
		}
		
		if (system(command) == -1)
		{
			perror("Error: Command not found");
		}
		
		free(command);
	}
	return 0;
}
