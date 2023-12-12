#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    int pipefd[2];
    pid_t child_pid;

    if (pipe(pipefd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    if ((child_pid = fork()) == -1) 
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) 
    {
        close(pipefd[0]);  
        dup2(pipefd[1], STDOUT_FILENO);  
        close(pipefd[1]);  
        
        execlp("ls", "ls", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else 
    {
        close(pipefd[1]);  
        dup2(pipefd[0], STDIN_FILENO); 
        close(pipefd[0]);  

        
        execlp("grep", "grep", "c", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}

