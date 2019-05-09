#include "ex1.h"
void* aligned_malloc(size_t size, size_t align){
	size_t offset = align - 1 + sizeof(void*);
	
	void*  oriPtr = malloc(size + offset);
	void** aliPtr = (void**)(((size_t)(oriPtr) + offset) &~(align - 1));

	aliPtr[-1] = oriPtr;

	return aliPtr;
}

void* aligned_free(void *ptr){
	free(((void**)ptr)[-1]);
}





