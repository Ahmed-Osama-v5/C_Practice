#include <stdio.h>
#include <stdlib.h>
#include "list.h"


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
	List_t list;
	createList(&list);
	listPushFront(&list, 6);
	listPushFront(&list, 5);
	listPushFront(&list, 4);
	listPushFront(&list, 3);
	listPushFront(&list, 2);
	listPushFront(&list, 1);

	listAddAfter(&list, 3, 9);

	traverseList(&list);

	printf("list has %s cycle\n", hasCycle(&list) ? "" : "no");
	printf("list middle is %d\n", getMiddle(&list));

	return 0;
}

/**********************************/


