#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 32

void printPrompt(void);
char *readCommand(void);
void executeCommand(char *command, char *args[]);
void parseArguments(char *input, char *args[], int *arg_count);


#endif
