/*
 * queue.h
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_


#define QUEUE_MAX_SIZE  (16)

typedef int queueKey_t;

/* Array based implementation */
/* *********************************************** */
typedef struct
{
	queueKey_t data[QUEUE_MAX_SIZE];
	int front;
    int back;
    int size;
}queue_t;

void createArrQueue(queue_t* pQueue);
int QueueArr_IsEmpty(queue_t* pQueue);
queueKey_t QueuekArr_Front(queue_t* pQueue);
void QueueArr_Enqueue(queue_t* pQueue, queueKey_t key);
queueKey_t QueueArr_Dequeue(queue_t* pQueue);

/* *********************************************** */

/* Linked based implementation */
/* *********************************************** */

typedef struct linkedQueue
{
	queueKey_t data;
	struct linkedQueue *pNextNode;
}queueNode_t;

typedef struct
{
	queueNode_t* pFront;
	queueNode_t* pBack;
	int size;
}linkedQueue_t;

void createLinkQueue(linkedQueue_t* pQueue);
int QueueLink_IsEmpty(linkedQueue_t* pQueue);
queueKey_t QueuekLink_Front(linkedQueue_t* pQueue);
void QueueLink_Enqueue(linkedQueue_t* pQueue, queueKey_t key);
queueKey_t QueueLink_Dequeue(linkedQueue_t* pQueue);

/* *********************************************** */

#endif /* INC_QUEUE_H_ */
