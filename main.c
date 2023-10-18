#include "shell.h"

int main() {
    char *command;

    while (1) {
        printPrompt();
        command = readCommand();

        if (command == NULL) {
            break;
        }

        executeCommand(command);
        free(command);
    }

    return 0;
}
