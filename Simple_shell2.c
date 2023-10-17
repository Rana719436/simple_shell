#include "simple_shell.h"
void Simple_shell2(void)
{
    char *args[] = {"ls", "-l", NULL};

    while (1)
    {
        pid_t pid = fork();

        if (pid == 0)
        {
            execvp(args[0], args);
            perror("Error");
            exit(EXIT_FAILURE);
        }
        else if (pid > 0)
        {
            wait(NULL);
            sleep(5);
        }
        else
        {
            perror("Error");
        }
    }
}

int main(void)
{
    Simple_shell2();
    return 0;
}
