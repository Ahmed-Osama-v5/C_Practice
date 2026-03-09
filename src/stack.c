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
