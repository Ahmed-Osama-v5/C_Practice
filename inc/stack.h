/*
 * stack.h
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */

#ifndef INC_STACK_H_
#define INC_STACK_H_

#define STACK_MAX_SIZE  3

typedef int stackKey_t;

/* Array based implementation */
/* *********************************************** */
typedef struct
{
	stackKey_t data[STACK_MAX_SIZE];
	int stackTop;
}stack_t;

void createArrStack(stack_t* pStack);
int StackArr_IsEmpty(stack_t* pStack);
int StackArr_IsFull(stack_t* pStack);
void StackArr_Push(stack_t* pStack, stackKey_t key);
void StackArr_Pop(stack_t* pStack);
stackKey_t StackArr_Top(stack_t* pStack);
void StackArr_Traverse(stack_t* pStack);

/* *********************************************** */

/* Linked based implementation */
/* *********************************************** */

/* *********************************************** */

#endif /* INC_STACK_H_ */
