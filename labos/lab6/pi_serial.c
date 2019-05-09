#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <math.h>
#define PI 3.14159

double pi = 0;
size_t range = 0; //BSS

void CalPI(){
    
    srand(time(NULL));

    size_t count = 0;
    for(size_t i = 0; i < range; i++){
        double x =  (double)rand()/RAND_MAX;
        double y =  (double)rand()/RAND_MAX;
        if(sqrt(x*x + y*y) <= 1.0) ++count;
    }
    
    pi = 4*(double)count/(double)range;
}

int main(int argc, char const *argv[])
{
    range = atoll(argv[1]);

    time_t timeStart, timeEnd;
    clock_t t = clock();
    time(&timeStart);

    CalPI();

    time(&timeEnd); 

    printf("%lf\n", pi); 
    printf("%li\n", timeEnd - timeStart);
    //printf("%li", (clock() - t)/CLOCKS_PER_SEC);
    return 0;
}
