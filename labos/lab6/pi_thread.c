#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define NUM_THREAD 8
//#define PI 3.14159

pthread_t threads[NUM_THREAD];
size_t count[NUM_THREAD] = {};
size_t range = 0;
double pi;


void *CalPI(void *arg){
    int tid = *((int*)arg);

    unsigned int random = rand()%30000;
    int subPoint = 0;
    for(size_t i = 0; i < range/NUM_THREAD; i++){
        double x = (double)rand_r(&random)/(double)RAND_MAX;
        double y = (double)rand_r(&random)/(double)RAND_MAX;
        if(sqrt(x*x + y*y) <= 1) ++subPoint;
    }

    count[tid] += subPoint;
    
}




int main(int argc, char const *argv[])
{
    range = atoll(argv[1]);

    int rc;
    
    int tid[NUM_THREAD] = {};

    time_t timeStart, timeEnd;
    
    time(&timeStart);
    clock_t t;
    t = clock(); 
    
    for(size_t i = 0; i < NUM_THREAD; i++){   
        tid[i] = i;
        rc = pthread_create(&threads[i], NULL, CalPI, (void*)&tid[i]);
        if(rc){
            printf("ERROR"); exit(-1);
        }
    }

    for(size_t i = 0; i < NUM_THREAD; i++){
        pthread_join(threads[i], NULL);
    }

    t = clock() - t;
    time(&timeEnd);

    size_t sumPoint = 0;
    for(size_t i = 0; i < NUM_THREAD; i++){
        sumPoint = sumPoint + count[i];
    }

    pi = 4.0*(double)sumPoint/(double)range;


    printf("PI      :  %lf\n", pi);
    //printf("clock_t :  %lf\n", (float)t/CLOCKS_PER_SEC);
    printf("time_t  :  %li", timeEnd - timeStart);
    
    

    return 0;
}
