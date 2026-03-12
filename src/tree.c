/*
 * tree.c
 *
 *  Created on: 11 Mar 2026
 *      Author: ahme.mohamed
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

TreeNode_t *newNode(TreeKey key)
{
	TreeNode_t* pNewNode = (TreeNode_t*) malloc(sizeof(TreeNode_t));
	if(pNewNode == NULL)
	{
		printf("newNode() error: new node ptr is null\n");
		return NULL;
	}

	pNewNode->key = key;
	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;

	return pNewNode;
}

void treeTraverse(TreeNode_t *pRoot)
{
    if (pRoot == NULL)
	{
		return;
	}

    printf("%d ", pRoot->key);
    treeTraverse(pRoot->pLeft);
    treeTraverse(pRoot->pRight);
}

TreeNode_t* treeAddNode(TreeNode_t* pRoot, TreeKey key)
{
	if (pRoot == NULL)
		return newNode(key);  /* found insertion point */

	if (key < pRoot->key)
		pRoot->pLeft  = treeAddNode(pRoot->pLeft, key);
	else if (key > pRoot->key)
		pRoot->pRight = treeAddNode(pRoot->pRight, key);
	/* if equal — duplicate, ignore */

	return pRoot;
}

