#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "stack.h"
#include "queue.h"


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
int isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(const char *pcStr)
{
	linkedStack_t stStack;
	createLinkStack(&stStack);

	    for (int i = 0; i < strlen(pcStr); i++)
	    {
	        char c = pcStr[i];

	        if (c == '(' || c == '[' || c == '{')
	        {
	        	StackLink_Push(&stStack, c);
	        }
	        else if (c == ')' || c == ']' || c == '}')
	        {
	            if (StackLink_IsEmpty(&stStack)) return 0;
	            if (!isMatching(stStack.pTop->data, c)) return 0;
	            StackLink_Pop(&stStack);
	        }
	    }
	    return StackLink_IsEmpty(&stStack);  /* must be empty at end */
}

char *mergeAlternately(char *word1, char *word2)
{
	int s32Len1   = strlen(word1);
	int s32Len2   = strlen(word2);
	char *pcResult = (char *)malloc(s32Len1 + s32Len2 + 1);
	if (pcResult == NULL) return NULL;

	int i1 = 0, i2 = 0, x = 0;

	while (i1 < s32Len1 || i2 < s32Len2)
	{
		if (i1 < s32Len1)
			pcResult[x++] = word1[i1++];

		if (i2 < s32Len2)
			pcResult[x++] = word2[i2++];
	}

	pcResult[x] = '\0';
	return pcResult;
}

int main(void)
{
	char* str1 = "abcr";
	char* str2 = "def";
	printf("string is %s\n", mergeAlternately(str1, str2));

	return 0;
}

/**********************************/


