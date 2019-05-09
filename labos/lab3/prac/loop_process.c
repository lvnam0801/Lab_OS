//source code of loop process c 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int timestamp = 0;
    while(1){
        printf("Time : %5d\n", timestamp++);
        sleep(1);
    }
    return 0;
}
