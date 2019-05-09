#if !defined(EX1_H)
#define EX1_H

#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t size, size_t align);
void* aligned_free(void *ptr);

#endif // EX1_H
