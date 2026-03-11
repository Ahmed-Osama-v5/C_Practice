/*
 * stack.h
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */

#ifndef INC_STACK_H_
#define INC_STACK_H_

#define STACK_MAX_SIZE  (16)

typedef char stackKey_t;

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
stackKey_t StackArr_Pop(stack_t* pStack);
stackKey_t StackArr_Top(stack_t* pStack);
void StackArr_Traverse(stack_t* pStack);

/* *********************************************** */

/* Linked based implementation */
/* *********************************************** */

typedef struct linkedStack
{
	stackKey_t data;
	struct linkedStack *pNextNode;
}stackNode_t;

typedef struct
{
	stackNode_t* pTop;
	int size;
}linkedStack_t;

void createLinkStack(linkedStack_t* pStack);
int StackLink_IsEmpty(linkedStack_t* pStack);
int StackLink_IsFull(linkedStack_t* pStack);
void StackLink_Push(linkedStack_t* pStack, stackKey_t key);
stackKey_t StackLink_Pop(linkedStack_t* pStack);
stackKey_t StackLink_Top(linkedStack_t* pStack);
void StackLink_Traverse(linkedStack_t* pStack);

/* *********************************************** */

#endif /* INC_STACK_H_ */
