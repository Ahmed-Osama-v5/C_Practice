/*
 * search.c
 *
 *  Created on: 12 Mar 2026
 *      Author: ahme.mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int linearSearch(int *pArr, int s32Len, int s32Target)
{
	int retVal = -1;
	if(pArr != NULL)
	{
		for(int i=0;i<s32Len;i++)
		{
			if(pArr[i] == s32Target)
			{
				retVal = i;
				break;
			}
		}
	}
	else
		printf("linearSearch() error: pArr ptr is null\n");

	return retVal;
}


int binarySearch(int *pArr, int s32Len, int s32Target)
{
	int retVal = -1;
	if(pArr != NULL)
	{
		int s32Left  = 0;
		int s32Right = s32Len - 1;

		while (s32Left <= s32Right)
		{
			int s32Mid = s32Left + (s32Right - s32Left) / 2;

			if (pArr[s32Mid] == s32Target)
			{
				retVal = s32Mid;
				break;
			}
			else if (pArr[s32Mid] < s32Target)
				s32Left  = s32Mid + 1;  /* search right half */
			else
				s32Right = s32Mid - 1;  /* search left half */
		}
	}
	else
		printf("linearSearch() error: pArr ptr is null\n");

	return retVal;
}
