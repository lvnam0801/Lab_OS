#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    switch (fork())
    {
        case  0:
            printf("This is child PID : %d\n", getpid());
            break;
    
        default:
            printf("This is parent process PID : %d\n", getpid());
            break;
        case -1:
            printf("fork failed!\n");
            break;
        
    }
    return 0;
}
