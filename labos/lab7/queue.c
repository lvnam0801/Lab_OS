
#include <stdlib.h>
#include "queue.h"
#include <pthread.h>
#include <assert.h>

/* Remember to initilize the queue before using it */
void initialize_queue(struct pqueue_t * q) {
	q->head = q->tail = NULL;
	pthread_mutex_init(&q->lock, NULL);
}

/* Return non-zero if the queue is empty */
int empty(struct pqueue_t * q) {
	return (q->head == NULL);
}

/* Get PCB of a process from the queue (q).
 * Return NULL if the queue is empty */
struct pcb_t * de_queue(struct pqueue_t * q) {
	// * catch error if q is null pointer
	assert(q != NULL);

	struct pcb_t * proc = NULL;
	// TODO: return q->head->data and remember to update the queue's head
	// and tail if necessary. Remember to use 'lock' to avoid race
	// condition
	
	// YOUR CODE HERE
	/* Use lock to avoid race condition */
	pthread_mutex_lock(&q->lock);

	if(empty(q)){
		pthread_mutex_unlock(&q->lock);
		return proc;
	}
	/* Get data from head pointer  */
	proc = q->head->data;
	/* Retain the head pointer */
	struct qitem_t * dlt = q->head;
	/* Update head pointer */
	if(q->head == q->tail) q->head = q->tail = NULL;
	else	q->head = q->head->next;		
	/* Free the memory just get data */
	free(dlt);	
	/* Release the lock to another process that access into pqueue_t */
	pthread_mutex_unlock(&q->lock);

	return proc;
}

/* Put PCB of a process to the queue. */
void en_queue(struct pqueue_t * q, struct pcb_t * proc) {
	// Catch error
	assert(q != NULL && proc != NULL);
	
	// TODO: Update q->tail.
	// Remember to use 'lock' to avoid race condition
	// YOUR CODE HERE

	/* Creat new qitem contain data of proc to en_queue into pqueue q */
	struct qitem_t* newProc = (struct qitem_t*)malloc(sizeof(struct qitem_t));
	newProc->data = proc;
	newProc->next = NULL;
	/* Use lock to avoid race condition */
	pthread_mutex_lock(&q->lock);
	/* enqueue new item in to pqueue q */
	if(empty(q))	q->head = q->tail = newProc;	// update head pointer and tail pointer
	else{									
		q->tail->next = newProc;
		q->tail = newProc;							// update tail pointer
	}
	/* Release the lock to another process that access into pqueue q */
	pthread_mutex_unlock(&q->lock);	
}


