#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int value = 5;

int main(int argc, char const *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid == 0){       //child process
        value += 15;
    }
    else if (pid > 0){  //parent process
        wait(NULL);
        printf("PARENT: value = %d", value);
    }
    else {
        perror("fork");
    }  
    return 0;
}
