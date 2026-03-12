#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "search.h"



int main(void)
{

	int arr[] = {5, 3, 1, 4, 2};
	for(int i=0;i<(sizeof(arr)/sizeof(int));i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d\n", linearSearch(arr, (sizeof(arr)/sizeof(arr[0])), 1));

	mergeSort(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1);
	printf("%d\n", binarySearch(arr, (sizeof(arr)/sizeof(arr[0])), 1));

	for(int i=0;i<(sizeof(arr)/sizeof(int));i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

/**********************************/


