#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "stack.h"


/* Floyd's algorithm */
int hasCycle(List_t* pList)
{
	int retVal = 0;
	if(pList != NULL)
	{
		/* if list is empty, return 0 */
		if(pList->pHead == NULL)
		{
			retVal = 0;
		}
		else
		{
			listNode_t* pSlow = pList->pHead;
			listNode_t* pFast = pList->pHead;

			while((pFast != NULL) && (pFast->pNextNode != NULL))
			{
				pSlow = pSlow->pNextNode;
				pFast = pFast->pNextNode->pNextNode;

				if(pSlow == pFast)
					retVal = 1;
			}
		}
	}
	else
	{
		printf("hsCycle(): list NULL ptr\n");
		retVal = 0;
	}
	return retVal;
}

int getMiddle(List_t* pList)
{
	if(pList != NULL)
	{
		/* if list is empty, return 0 */
		if(pList->pHead == NULL)
		{
			return 0;
		}
		else
		{
			listNode_t* pSlow = pList->pHead;
			listNode_t* pFast = pList->pHead;

			while((pFast != NULL) && (pFast->pNextNode != NULL))
			{
				pSlow = pSlow->pNextNode;
				pFast = pFast->pNextNode->pNextNode;
			}
			return pSlow->data;
		}
	}
	else
	{
		printf("getMiddle(): list NULL ptr\n");
		return 0;
	}
}


int main(void)
{
	linkedStack_t stack;
	createLinkStack(&stack);

	StackLink_Push(&stack, 12);
	StackLink_Push(&stack, 24);
	StackLink_Push(&stack, 36);
	StackLink_Push(&stack, 48);
	StackLink_Traverse(&stack);
	StackLink_Pop(&stack);
	StackLink_Traverse(&stack);
	StackLink_Pop(&stack);
	StackLink_Traverse(&stack);
	StackLink_Pop(&stack);
	StackLink_Traverse(&stack);
	StackLink_Pop(&stack);

	printf("stack top: %d\n", StackLink_Top(&stack));

	return 0;
}

/**********************************/


