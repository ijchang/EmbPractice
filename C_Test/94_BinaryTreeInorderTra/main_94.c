#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the root of a binary tree, return the inorder traversal of its nodes' values.

//Input: root = [1,null,2,3]
//Output: [1,3,2]

//Input: root = []
//Output: []

//Input: root = [1]
//Output: [1]

//The number of nodes in the tree is in the range [0, 100].
//-100 <= Node.val <= 100



// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

struct stack{
    int size;
    int top;
    struct TreeNode* items[100];
};

void pushStack(struct stack *p_treeStack, struct TreeNode* p_node)
{
    p_treeStack->items[++p_treeStack->top] = p_node;
    p_treeStack->size++;
    return;
}

struct TreeNode* popStack(struct stack *p_treeStack)
{
    if(p_treeStack->size == 0)
    {
        return NULL;
    }

    p_treeStack->size--;
    return p_treeStack->items[p_treeStack->top--];
}

bool stackEmpty(struct stack *p_treeStack)
{
    if(p_treeStack->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int size = 0;

void getVal(struct TreeNode* p_node, int* p_array)
{
    if(p_node == NULL){
        return;
    }

    getVal(p_node->left, p_array);
    *(p_array + size) = p_node->val;
    size++;
    getVal(p_node->right, p_array);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* inorderTraversal(struct TreeNode* root, int* returnSize){

//Iterative version
/*
    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    struct stack treeStack;
    treeStack.size = 0;
    treeStack.top = -1;
    size = 0;

    int *p_array = malloc(100 * sizeof(int));

    while((root != NULL) || (stackEmpty(&treeStack) == false)){
        if(root != NULL){
            pushStack(&treeStack, root);
            root = root->left;
        }
        else{
            root = popStack(&treeStack);
            //print(root->val);
            *(p_array + size) = root->val;
            size++;
            root = root->right;
        }
    }

    *returnSize = size;
    return p_array;
*/

//Recursive version

    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    size = 0;
    int *p_array = malloc(100 * sizeof(int));

    getVal(root, p_array);

    *returnSize = size;
    return p_array;
}


int main(void)
{
    return 0;
}



