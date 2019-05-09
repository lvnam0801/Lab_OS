#include "readline.h"

int read_line(char *str){
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] < 48 || str[i] > 57) return 0;
        ++i;
    }
    return 1;
}