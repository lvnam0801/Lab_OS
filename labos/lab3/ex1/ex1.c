#include "readfile.h"
#include "linked_list.h"
#include <unistd.h>

unsigned int countDiv(Node *, unsigned int );

int main(int argc, char const *argv[])
{   
    Node *list = NULL;
    readfile(&list);

    // Creat 2 process 
    int ps1, ps2;
    ps1 = fork();
    
    //Process fork
    if(ps1 == 0){
        printf("Divisible by 2 : %d\n", countDiv(list, 2));
        exit(EXIT_SUCCESS);
    }
    else if(ps1 > 0){
        ps2 = fork();
        if(ps2 == 0){
            printf("Divisible by 3 : %d\n", countDiv(list, 3));
            exit(EXIT_SUCCESS);
        }
        else if(ps2 > 0){
            printf("Divisible by 5 : %d\n", countDiv(list, 5));
            exit(EXIT_SUCCESS);
        }
        else{
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
    else{
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}

// Count the number of list divisible by base   
unsigned int countDiv(Node *list, unsigned int base){
    int ret = 0;
    while(list != NULL){
        if(!(list->data%base)) ++ret;
        list = list->next;
    }
    return ret;
}