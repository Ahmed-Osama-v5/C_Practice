/*
 * list.c
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void createList(List_t* pList)
{
	if(pList != NULL)
	{
		pList->pHead = NULL;
	}
	else
	{
		printf("Can't create list with NULL ptr\n");
	}
}

/* Insert at head — O(1) */
void listPushFront(List_t* pList, listKey_t key)
{
	if(pList != NULL)
	{
	    listNode_t *pNewNode = (listNode_t *)malloc(sizeof(listNode_t));
	    pNewNode->data = key;
	    pNewNode->pNextNode = pList->pHead;
	    pList->pHead = pNewNode;
	}
	else
	{
		printf("listPushFront(): error: list ptr is NULL\n");
	}
}

void listPopFront(List_t* pList)
{
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("listPopFront(): error: list head ptr is NULL\n");
		}
		else
		{
			listNode_t* pTmpNode = pList->pHead;

			pList->pHead = pList->pHead->pNextNode;

			free(pTmpNode);
		}
	}
	else
	{
		printf("listPopFront(): error: list ptr is NULL\n");
	}
}

listKey_t listTopFront(List_t* pList)
{
	listKey_t retKey = 0;
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("listTopFront(): error: list head ptr is NULL\n");
		}
		else
		{
			retKey = pList->pHead->data;
		}
	}
	else
	{
		printf("listTopFront(): error: list ptr is NULL\n");
	}

	return retKey;
}

void listPushBack(List_t* pList, listKey_t key)
{
	if(pList != NULL)
	{
	    listNode_t *pNewNode = (listNode_t *)malloc(sizeof(listNode_t));
	    listNode_t* pTmpNode = pList->pHead;
	    pNewNode->data = key;
	    pNewNode->pNextNode = NULL;

	    while(pTmpNode->pNextNode != NULL)
	    	pTmpNode = pTmpNode->pNextNode;
	    pTmpNode->pNextNode = pNewNode;
	}
	else
	{
		printf("listPushBack(): error: list ptr is NULL\n");
	}
}

void listPopBack(List_t* pList)
{
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("listPopBack(): error: list head ptr is NULL\n");
		}
		else
		{
			listNode_t* pTmpNode = pList->pHead;

		    while(pTmpNode->pNextNode->pNextNode != NULL)
		    	pTmpNode = pTmpNode->pNextNode;

		    listNode_t* pLastNode = pTmpNode->pNextNode;
		    pTmpNode->pNextNode = NULL;
			free(pLastNode);
		}
	}
	else
	{
		printf("listPopBack(): error: list ptr is NULL\n");
	}
}

listKey_t listTopBack(List_t* pList)
{
	listKey_t retKey = 0;
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("listTopBack(): error: list head ptr is NULL\n");
		}
		else
		{
			listNode_t* pTmpNode = pList->pHead;

		    while(pTmpNode->pNextNode != NULL)
		    	pTmpNode = pTmpNode->pNextNode;

		    retKey = pTmpNode->data;
		}
	}
	else
	{
		printf("listTopBack(): error: list ptr is NULL\n");
	}

	return retKey;
}

void listAddAfter(List_t* pList, listKey_t afterKey, listKey_t newKey)
{
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("listAddAfter(): error: list head ptr is NULL\n");
		}
		else
		{
			listNode_t* pNewNode = (listNode_t*) malloc(sizeof(listNode_t));
			pNewNode->data = newKey;

			listNode_t* pTmpNode = pList->pHead;

			while(pTmpNode->data != afterKey)
				pTmpNode = pTmpNode->pNextNode;

			pNewNode->pNextNode = pTmpNode->pNextNode;
			pTmpNode->pNextNode = pNewNode;
		}
	}
	else
	{
		printf("listAddAfter(): error: list ptr is NULL\n");
	}
}


/* Traverse — O(n) */
void traverseList(List_t* pList)
{
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("traverseList(): error: list head ptr is NULL\n");
		}
		else
		{
			listNode_t* pTmpNode = pList->pHead;

			while(pTmpNode != NULL)
			{
				printf("Data: %d\n", pTmpNode->data);
				pTmpNode = pTmpNode->pNextNode;
			}
		}
	}
	else
	{
		printf("traverseList(): error: list ptr is NULL\n");
	}
}

void listReverse(List_t* pList)
{
	if(pList != NULL)
	{
		if(pList->pHead == NULL)
		{
			printf("listReverse(): error: list head ptr is NULL\n");
		}
		else
		{
			listNode_t* pNext = NULL;
			listNode_t* pCurrent = pList->pHead;
			listNode_t* pPrev = NULL;

			while(pCurrent != NULL)
			{
				pNext = pCurrent->pNextNode;
				pCurrent->pNextNode = pPrev;
				pPrev = pCurrent;
				pCurrent = pNext;
			}
			pList->pHead = pPrev;
		}
	}
	else
	{
		printf("listReverse(): error: list ptr is NULL\n");
	}
}
