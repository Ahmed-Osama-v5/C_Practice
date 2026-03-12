/*
 * tree.h
 *
 *  Created on: 11 Mar 2026
 *      Author: ahme.mohamed
 */

#ifndef INC_TREE_H_
#define INC_TREE_H_


typedef int TreeKey;

typedef struct TreeNode
{
    TreeKey            key;
    struct TreeNode   *pLeft;
    struct TreeNode   *pRight;
} TreeNode_t;

TreeNode_t *newNode(TreeKey key);
void treeTraverse(TreeNode_t *pRoot);
TreeNode_t* treeAddNode(TreeNode_t* pRoot, TreeKey key);


#endif /* INC_TREE_H_ */
