/*
 * list.h
 *
 *  Created on: 9 Mar 2026
 *      Author: ahme.mohamed
 */

#ifndef LIST_H_
#define LIST_H_

/**
 * single Linked list
 * */

typedef int listKey_t;

/* Node */
typedef struct Node
{
	listKey_t data;
	struct Node *pNextNode;
}listNode_t;

typedef struct
{
	listNode_t* pHead;
}List_t;


void createList(List_t* pList);

void listPushFront(List_t* pList, listKey_t key);
void listPopFront(List_t* pList);
listKey_t listTopFront(List_t* pList);

void listPushBack(List_t* pList, listKey_t key);
void listPopBack(List_t* pList);
listKey_t listTopBack(List_t* pList);

void listAddAfter(List_t* pList, listKey_t afterKey, listKey_t newKey);

void traverseList(List_t* pList);

void listReverse(List_t* pList);


#endif /* LIST_H_ */
