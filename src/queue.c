/*
 * queue.c
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



/* Array based implementation */
/* *********************************************** */

void createArrQueue(queue_t* pQueue)
{
	if(pQueue != NULL)
	{
		pQueue->front = 0;
		pQueue->back = 0;
		pQueue->size = 0;
	}
	else
		printf("createArrQueue() error: queue ptr is NULL\n");
}

int QueueArr_IsEmpty(queue_t* pQueue)
{
	int retVal = 0;
	if(pQueue != NULL)
	{
		retVal = (pQueue->size > 0) ? 0 : 1;
	}
	else
		printf("QueueArr_IsEmpty() error: queue ptr is NULL\n");

	return retVal;
}

queueKey_t QueuekArr_Front(queue_t* pQueue)
{
	queueKey_t retVal = 0;
	if(pQueue != NULL)
	{
		if(! QueueArr_IsEmpty(pQueue))
			retVal = pQueue->data[pQueue->front];
		else
			printf("QueuekArr_Front() error: queue is empty\n");
	}
	else
		printf("QueuekArr_Front() error: queue ptr is NULL\n");

	return retVal;
}

void QueueArr_Enqueue(queue_t* pQueue, queueKey_t key)
{
	if(pQueue != NULL)
	{
		if(pQueue->size < QUEUE_MAX_SIZE)
		{
			pQueue->data[pQueue->back] = key;
			pQueue->back = (pQueue->back + 1) % QUEUE_MAX_SIZE;
			pQueue->size++;
		}
		else
			printf("QueueArr_Enqueue() error: queue is full\n");
	}
	else
		printf("QueueArr_Enqueue() error: queue ptr is NULL\n");
}

queueKey_t QueueArr_Dequeue(queue_t* pQueue)
{
	queueKey_t retVal = 0;
	if(pQueue != NULL)
	{
		if(! QueueArr_IsEmpty(pQueue))
		{
			retVal = pQueue->data[pQueue->front];

			pQueue->front = (pQueue->front + 1) % QUEUE_MAX_SIZE;
			pQueue->size--;
		}
		else
			printf("QueueArr_Dequeue() error: queue is empty\n");
	}
	else
		printf("QueueArr_Dequeue() error: queue ptr is NULL\n");

	return retVal;
}

/* *********************************************** */

/* Linked based implementation */
/* *********************************************** */

void createLinkQueue(linkedQueue_t* pQueue)
{
	if(pQueue != NULL)
	{
		pQueue->pFront = NULL;
		pQueue->pBack = NULL;
		pQueue->size = 0;
	}
	else
		printf("createLinkQueue() error: queue ptr is NULL\n");
}

int QueueLink_IsEmpty(linkedQueue_t* pQueue)
{
	int retVal = 0;
	if(pQueue != NULL)
	{
		retVal = (pQueue->size == 0) ? 1 : 0;
	}
	else
		printf("QueueLink_IsEmpty() error: queue ptr is NULL\n");

	return retVal;
}

queueKey_t QueuekLink_Front(linkedQueue_t* pQueue)
{
	queueKey_t retVal = 0;
	if(pQueue != NULL)
	{
		if(! QueueLink_IsEmpty(pQueue))
		{
			retVal = pQueue->pFront->data;
		}
		else
			printf("QueuekLink_Front() error: queue is empty\n");
	}
	else
		printf("QueuekLink_Front() error: queue ptr is NULL\n");

	return retVal;
}

void QueueLink_Enqueue(linkedQueue_t* pQueue, queueKey_t key)
{
	if(pQueue != NULL)
	{
		if(pQueue->size < QUEUE_MAX_SIZE)
		{
			queueNode_t* pNew = (queueNode_t*) malloc(sizeof(queueNode_t));
			if(pNew != NULL)
			{
				pNew->data = key;
				pNew->pNextNode = NULL;

				if(QueueLink_IsEmpty(pQueue))
				{
					pQueue->pFront = pNew;
				}
				else
				{
					pQueue->pBack->pNextNode = pNew;
				}

				pQueue->pBack = pNew;
				pQueue->size++;
			}
			else
				printf("QueueLink_Enqueue() error: couldn't create a new node\n");
		}
		else
			printf("QueueLink_Enqueue() error: queue is full\n");
	}
	else
		printf("QueueLink_Enqueue() error: queue ptr is NULL\n");
}

queueKey_t QueueLink_Dequeue(linkedQueue_t* pQueue)
{
	queueKey_t retVal = 0;
	if(pQueue != NULL)
	{
		if(! QueueLink_IsEmpty(pQueue))
		{
			queueNode_t* pTmp = pQueue->pFront;
			retVal = pTmp->data;
			pQueue->pFront = pQueue->pFront->pNextNode;
			pQueue->size--;

			if(pQueue->pFront == NULL)
				pQueue->pBack = NULL;

			free(pTmp);
		}
		else
		{
			printf("QueueLink_Dequeue() error: queue is empty\n");
		}
	}
	else
		printf("QueueLink_Dequeue() error: queue ptr is NULL\n");

	return retVal;
}


/* *********************************************** */
