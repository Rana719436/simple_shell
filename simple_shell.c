#include "simple_shell.h"
void display_pro();

/**
 * display_pro - Prints a new prompt 
 */

void display_pro()
{
	char pro[] = "#cisfun$";
	write(STDOUT_FILENO, pro, sizeof(pro) - 1);
}

/**
 * main - Prints a Simple shell
 * Return: Always 0
 */

int main()
{
	char *k = NULL;
	ssize_t i;
	size_t l;
	int len;
	while (1)
	{
		display_pro();
		i = getline(&k, &l, stdin);
		l = 0;
		if (i == -1)
		{
			char newline = '\n';
			write(STDOUT_FILENO, &newline, 1);
			free(k);
			break;
		}
		len = strlen(k);
		if (command[len-1] == '\n')
		{
			command[len-1] = '\0';
		}
		if (system(k) == -1)
		{
			perror("Error: Command not found");
		}
		free(k);
	}
	return 0;
}
