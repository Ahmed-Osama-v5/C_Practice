/*
 * sort.h
 *
 *  Created on: 11 Mar 2026
 *      Author: ahme.mohamed
 */

#ifndef INC_SORT_H_
#define INC_SORT_H_

void bubbleSort(int *pArr, int s32Len);
void selectionSort(int *pArr, int s32Len);
void insertionSort(int *pArr, int s32Len);
void mergeSort(int *pArr, int s32Left, int s32Right);
void quickSort(int *pArr, int s32Low, int s32High);

#endif /* INC_SORT_H_ */
