#if !defined(LINKED_LIST_H)
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} Node;

void Add(Node**, int);

#endif // LINKED_LIST_H
