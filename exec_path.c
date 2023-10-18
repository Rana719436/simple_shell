/**
 * findCommandPath - fuunction to handle path
 * @command: constant char
 * Return: null
 */

#include "shell.h"

char *findCommandPath(const char *command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

	while (token != NULL)
	{
		char full_path[MAX_INPUT_SIZE];

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			return (strdup(full_path));
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}
