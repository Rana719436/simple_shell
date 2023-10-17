#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main() {
    char *command = NULL;
    size_t command_len = 0;
    ssize_t bytes_read;
    pid_t child_pid;

    while (1) {
	if (isatty(STDIN_FILENO)) {
            write(STDOUT_FILENO, "#cisfun$ ", 9);
        }    
      
        bytes_read = getline(&command, &command_len, stdin);

        if (bytes_read == -1) {
		if (isatty(STDIN_FILENO)){
     
            write(STDOUT_FILENO, "\n", 1);
		}

            break;
	    free (command);
        }


        if (bytes_read > 0 && command[bytes_read - 1] == '\n') {
            command[bytes_read - 1] = '\0';
        }

        child_pid = fork();

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

    free(command);
    return 0;
}
