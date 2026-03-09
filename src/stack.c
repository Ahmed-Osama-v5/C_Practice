/*
 * stack.c
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/* Array based implementation */
/* *********************************************** */

void createArrStack(stack_t* pStack)
{
	if(pStack != NULL)
	{
		pStack->stackTop = -1;
	}
	else
	{
		printf("createArrStack(): error: list ptr is NULL\n");
	}
}

int StackArr_IsEmpty(stack_t* pStack)
{
	int retVal = 0;
	if(pStack != NULL)
	{
		retVal = ((pStack->stackTop >= 0) ? 0 : 1);
	}
	else
	{
		printf("StackArr_IsEmpty(): error: list ptr is NULL\n");
	}
	return retVal;
}

int StackArr_IsFull(stack_t* pStack)
{
	int retVal = 0;
	if(pStack != NULL)
	{
		retVal = ((pStack->stackTop == (STACK_MAX_SIZE-1)) ? 1 : 0);
	}
	else
	{
		printf("StackArr_IsFull(): error: list ptr is NULL\n");
	}
	return retVal;
}

void StackArr_Push(stack_t* pStack, stackKey_t key)
{
	if(pStack != NULL)
	{
		if(! StackArr_IsFull(pStack))
		{
			pStack->data[++pStack->stackTop] = key;
		}
		else
		{
			printf("StackArr_Push(): error: stack is full\n");
		}
	}
	else
	{
		printf("StackArr_Push(): error: list ptr is NULL\n");
	}
}

void StackArr_Pop(stack_t* pStack)
{
	if(pStack != NULL)
	{
		if(! StackArr_IsEmpty(pStack))
		{
			pStack->stackTop--;
		}
		else
		{
			printf("StackArr_Pop(): error: stack is empty\n");
		}
	}
	else
	{
		printf("StackArr_Pop(): error: list ptr is NULL\n");
	}
}

stackKey_t StackArr_Top(stack_t* pStack)
{
	stackKey_t retVal = 0;
	if(pStack != NULL)
	{
		if(StackArr_IsEmpty(pStack))
		{
			printf("StackArr_Top(): error: stack is empty\n");
		}
		else
			retVal = pStack->data[pStack->stackTop];
	}
	else
	{
		printf("StackArr_Top(): error: list ptr is NULL\n");
	}
	return retVal;
}

void StackArr_Traverse(stack_t* pStack)
{
	if(pStack != NULL)
	{
		if(! StackArr_IsEmpty(pStack))
		{
			for(int i=0;i<=pStack->stackTop;i++)
			{
				printf("Element #%d: %d\n", i, pStack->data[i]);
			}
		}
		else
		{
			printf("StackArr_Traverse(): error: stack is empty\n");
		}
	}
	else
	{
		printf("StackArr_Traverse(): error: list ptr is NULL\n");
	}
}

/* *********************************************** */


/* Array based implementation */
/* *********************************************** */

void createLinkStack(linkedStack_t* pStack)
{
	pStack->pTop = NULL;
	pStack->size = 0;
}

int StackLink_IsEmpty(linkedStack_t* pStack)
{
	stackKey_t retVal = 0;
	if(pStack != NULL)
	{
		if(pStack->size <= 0)
		{
			printf("StackLink_IsEmpty(): stack is empty\n");
			retVal = 1;
		}
		else
			retVal = 0;
	}
	else
	{
		printf("StackLink_IsEmpty(): error: list ptr is NULL\n");
	}
	return retVal;
}

int StackLink_IsFull(linkedStack_t* pStack)
{
	stackKey_t retVal = 0;
	if(pStack != NULL)
	{
		if(pStack->size == STACK_MAX_SIZE)
		{
			printf("StackLink_IsFull(): stack is full\n");
			retVal = 1;
		}
		else
			retVal = 0;
	}
	else
	{
		printf("StackLink_IsFull(): error: list ptr is NULL\n");
	}
	return retVal;
}

void StackLink_Push(linkedStack_t* pStack, stackKey_t key)
{
	if(pStack != NULL)
	{
		if(! StackLink_IsFull(pStack))
		{
			stackNode_t* pNewNode = (stackNode_t*) malloc(sizeof(stackNode_t));

			pNewNode->data = key;
			pNewNode->pNextNode = pStack->pTop;
			pStack->pTop = pNewNode;
			pStack->size++;
		}
		else
			printf("StackLink_Push(): error: stack is full\n");
	}
	else
	{
		printf("StackLink_Push(): error: list ptr is NULL\n");
	}
}

void StackLink_Pop(linkedStack_t* pStack)
{
	if(pStack != NULL)
	{
		if(! StackLink_IsEmpty(pStack))
		{
			stackNode_t* pTmpNode = pStack->pTop;

			pStack->pTop = pTmpNode->pNextNode;
			pStack->size--;

			free(pTmpNode);
		}
		else
			printf("StackLink_Pop(): error: stack is empty\n");
	}
	else
	{
		printf("StackLink_Pop(): error: list ptr is NULL\n");
	}
}

stackKey_t StackLink_Top(linkedStack_t* pStack)
{
	stackKey_t retVal = 0;
	if(pStack != NULL)
	{
		if(StackLink_IsEmpty(pStack))
		{
			printf("StackLink_Top(): error: stack is empty\n");
		}
		else
			retVal = pStack->pTop->data;
	}
	else
	{
		printf("StackLink_Top(): error: list ptr is NULL\n");
	}
	return retVal;
}

void StackLink_Traverse(linkedStack_t* pStack)
{
	if(pStack != NULL)
	{
		if(! StackLink_IsEmpty(pStack))
		{
			stackNode_t* pTmpNode = pStack->pTop;
			for(int i=0;i<pStack->size;i++)
			{
				printf("Element #%d: %d\n", i, pTmpNode->data);
				pTmpNode = pTmpNode->pNextNode;
			}
		}
		else
			printf("StackLink_Traverse(): error: stack is empty\n");
	}
	else
	{
		printf("StackLink_Traverse(): error: list ptr is NULL\n");
	}
}

/* *********************************************** */
