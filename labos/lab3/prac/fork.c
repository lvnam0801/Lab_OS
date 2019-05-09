#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>     //defind fork(), and pid_t

int main(int argc, char const *argv[])
{
        __pid_t child_pid;

        // left fork() of child process
        child_pid = fork();

        ///∗ check what the fork() call actually did
        if(child_pid == -1) {
            perror("fork"); // print a system-definded error messenger
            exit(1);
        }

        if(child_pid == 0){
            // fork successed we were insilde the child process
            printf("Hello, ");
            fflush(stdout); 
        }
        else{
            //fork() successed were inside the parent process 
            printf ("World!\n");
            fflush(stdout);
        }
        

    return 0;
}
