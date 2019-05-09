#include "linked_list.h"

void Add(Node **list, int data){
    //Initialize the value of node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // Insert node into the linked list(if list null)
    if(*list == NULL) {
        *list = newNode;
        return;
    }
    // Insert node into the linked list (list is not null)
    Node *pNode = *list;
    while(pNode->next != NULL)
        pNode = pNode->next;
    pNode->next = newNode;
}
