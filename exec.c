#include "shell.h"

void executeCommand(char *command) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
    } else if (child_pid == 0) {
        char *args[] = {NULL, NULL};
        args[0] = strdup(command);
        execve(args[0], args, NULL);

        perror("./shell");
        exit(1);
    } else {
        int status;
        if (wait(&status) == -1) {
            perror("wait");
        }
    }
}
