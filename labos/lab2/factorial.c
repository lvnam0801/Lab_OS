#include "factorial.h"
char *factorial(const int aNumber){
    
    int fac = 1, numOfArr = 1, temp;
    
    //calculate factorial of aNumber
    for(int i = 2; i <= aNumber; ++i){
        numOfArr = 0;
        fac *= i ;
    }
    
    temp = fac;
    //find the number of element in array
    while(fac >= 1){
        fac /= 10;
        numOfArr++;
    }

    char* ret = (char*)malloc(sizeof(char)*(numOfArr + 1));
    sprintf(ret, "%d", temp);   //convert from type int into char array
    return ret;    
}