#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    // First child process
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    else if (pid == 0)
    {
        printf("First child is running...\n");
        sleep(2);
        printf("First child is terminating.\n");
        return 0;
    }

    else
    {
        // Parent waits for any child
        wait(NULL);
        printf("Parent: wait() completed.\n");
    }

    // Second child process
    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    else if (pid == 0)
    {
        printf("Second child is running...\n");
        sleep(1);
        printf("Second child is terminating.\n");
        return 0;
    }

    else
    {
        // Parent waits for a specific child
        waitpid(pid, NULL, 0);
        printf("Parent: waitpid() completed.\n");
    }

    return 0;
}
