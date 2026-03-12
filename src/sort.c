/*
 * sort.c
 *
 *  Created on: 11 Mar 2026
 *      Author: ahme.mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"



void bubbleSort(int *pArr, int s32Len)
{
	for(int i=0;i<s32Len-1;i++)
	{
		int bSwapped = 0;
		for(int j=0;j<s32Len-1-i;j++)
		{
			if(pArr[j] > pArr[j+1])
			{
				int tmp = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = tmp;

				bSwapped = 1;
			}
		}
		if(! bSwapped)
			break;
	}
}


void selectionSort(int *pArr, int s32Len)
{
	for(int i=0;i<s32Len-1;i++)
	{
		int x = i;
		for(int j=i+1;j<s32Len;j++)
		{
			if(pArr[j] < pArr[x])
				x = j;
		}
		if (x != i)
		{
			int tmp = pArr[i];
			pArr[i] = pArr[x];
			pArr[x] = tmp;
		}
	}
}


void insertionSort(int *pArr, int s32Len)
{

	for(int i=1;i<s32Len;i++)
	{
		int j = i;
		while((j>0) && (pArr[j] < pArr[j-1]))
		{
			int tmp = pArr[j];
			pArr[j] = pArr[j-1];
			pArr[j-1] = tmp;
			j--;
		}
	}
}


static void merge(int *pArr, int s32Left, int s32Mid, int s32Right)
{
    int s32Len1 = s32Mid - s32Left + 1;
    int s32Len2 = s32Right - s32Mid;

    /* Temp arrays */
    int as32L[s32Len1];
    int as32R[s32Len2];

    for (int i = 0; i < s32Len1; i++) as32L[i] = pArr[s32Left + i];
    for (int j = 0; j < s32Len2; j++) as32R[j] = pArr[s32Mid + 1 + j];

    int i = 0, j = 0, k = s32Left;

    /* Merge back into original array */
    while (i < s32Len1 && j < s32Len2)
    {
        if (as32L[i] <= as32R[j])
            pArr[k++] = as32L[i++];
        else
            pArr[k++] = as32R[j++];
    }

    while (i < s32Len1) pArr[k++] = as32L[i++];
    while (j < s32Len2) pArr[k++] = as32R[j++];
}

void mergeSort(int *pArr, int s32Left, int s32Right)
{
    if (s32Left >= s32Right) return;  /* base case — single element */

    int s32Mid = s32Left + (s32Right - s32Left) / 2;  /* avoids overflow vs (l+r)/2 */

    mergeSort(pArr, s32Left,      s32Mid);
    mergeSort(pArr, s32Mid + 1,   s32Right);
    merge(pArr, s32Left, s32Mid, s32Right);
}

static int partition(int *pArr, int s32Low, int s32High)
{
    int s32Pivot = pArr[s32High];  /* last element as pivot */
    int i        = s32Low - 1;

    for (int j = s32Low; j < s32High; j++)
    {
        if (pArr[j] <= s32Pivot)
        {
            i++;
            int s32Tmp  = pArr[i];
            pArr[i]     = pArr[j];
            pArr[j]     = s32Tmp;
        }
    }

    /* Place pivot in correct position */
    int s32Tmp      = pArr[i + 1];
    pArr[i + 1]     = pArr[s32High];
    pArr[s32High]   = s32Tmp;

    return i + 1;  /* pivot index */
}

void quickSort(int *pArr, int s32Low, int s32High)
{
    if (s32Low >= s32High) return;

    int s32PivotIdx = partition(pArr, s32Low, s32High);

    quickSort(pArr, s32Low,             s32PivotIdx - 1);
    quickSort(pArr, s32PivotIdx + 1,    s32High);
}
