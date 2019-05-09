#if !defined(MAIN)
#define MAIN

#include "factorial.h"
#include "readline.h"

int main(int argc, char const *argv[])
{
    char *str = (char*)malloc(sizeof(char)*51);
    scanf("%[^\n]%*c", str);

    if(read_line(str)){
        int value;
        sscanf(str, "%d", &value);
        printf("%s\n", factorial(value));

    }
    else
        printf("-1\n");
    return 0;
}



#endif // MAIN

