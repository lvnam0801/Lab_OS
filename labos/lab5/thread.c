#include <pthread.h>
#include <stdio.h>
#define NUMBERS 26

void* printLeter(void* i){
    size_t tid = *((long*)i);
    printf("%c", (char)(65 + tid));
}

int main(int argc, char const *argv[])
{
    pthread_t threads[NUMBERS];

    int rc;

    int tid[NUMBERS];

    for(size_t i = 0; i < NUMBERS; i++){
        tid[i] = i;
        rc = pthread_create(&threads[i], NULL, printLeter, (void*)&tid[i]);

        if(rc){
            printf("error");
            pthread_exit(NULL);
        }
       
    }
    for(size_t i = 0; i < NUMBERS; i++){
         pthread_join(threads[i], NULL);
    }
    
    return 0;
}
