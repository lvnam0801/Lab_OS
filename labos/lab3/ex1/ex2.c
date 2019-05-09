#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int b, c, d, e, f, g, i;

    // This is process B
    if(!(b = fork())){
        //This is process E
        if(!(e = fork())){
            printf("This is process E : %d\n", getpid());
            //exit(EXIT_SUCCESS);
        }
        else{
            //This is proces F
            if(!(f = fork())){
                printf("This is process F : %d\n", getpid());
                //exit(EXIT_SUCCESS);
            }
            else{
                printf("This is process B : %d\n", getpid());
                //exit(EXIT_SUCCESS);
            }
            
        }
    }
    // This is process A
    else{
        // This is process C
        if(!(c = fork())){
            // This is process G
            if(!(g = fork())){
                // This is process I
                if(!(i = fork())){
                    printf("This is process I : %d\n", getpid());
                    //exit(EXIT_SUCCESS);
                }
                else{
                    printf("This is process G : %d\n", getpid());
                    //exit(EXIT_SUCCESS);
                }
            }
            else{
                printf("This is process C : %d\n", getpid());
                //exit(EXIT_SUCCESS);
            }
        }
        else{
            // This is process D
            if(!(d = fork())){
                printf("This is process D : %d\n", getpid());
                //exit(EXIT_SUCCESS);
            }
            // This is process A
            else{
                printf("This is process A : %d\n", getpid());
                //exit(EXIT_SUCCESS);
            }
        }
    }
    sleep(10);
    return 0;
}
