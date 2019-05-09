#include "ex1.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int *ptr = aligned_malloc(10,64);
    printf("%p\n", ptr);
    aligned_free(ptr);
    return 0;
}
