#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree
//and postorder is the postorder traversal of the same tree, construct and return the binary tree.

    3
   / \
  9  20
    /  \
   15   7

//Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//Output: [3,9,20,null,null,15,7]

//Input: inorder = [-1], postorder = [-1]
//Output: [-1]

//1 <= inorder.length <= 3000
//postorder.length == inorder.length
//-3000 <= inorder[i], postorder[i] <= 3000
//inorder and postorder consist of unique values.
//Each value of postorder also appears in inorder.
//inorder is guaranteed to be the inorder traversal of the tree.
//postorder is guaranteed to be the postorder traversal of the tree.


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

#define CAPACITY 2000

#define ASSERT(condition) while(!(condition)){};

struct stackEntry{
    struct stackEntry *p_pre;
    struct TreeNode* p_treeNode;
    int depth;
};

struct stack{
    int size;
    struct stackEntry *p_top;
};

struct stack* stackCreate(void){
    struct stack *p_stack = malloc(sizeof(struct stack));
    p_stack->size = 0;
    p_stack->p_top = NULL;

    return p_stack;
}

struct stackEntry* stackPop(struct stack* p_stack){
    if(p_stack->size == 0){
        return NULL;
    }

    p_stack->size--;
    struct stackEntry *p_tmpEntry = p_stack->p_top;
    p_stack->p_top = p_stack->p_top->p_pre;
    ASSERT(p_tmpEntry != NULL);
printf("pop:stackSize = %d\n", p_stack->size);

    return p_tmpEntry;
}

void stackPush(struct stack* p_stack, struct stackEntry* p_stackEntry){
    if(p_stack->size == CAPACITY){
        return;
    }
    p_stackEntry->p_pre = p_stack->p_top;
    p_stack->p_top = p_stackEntry;
    p_stack->size++;
printf("push:stackSize = %d\n", p_stack->size);
}

bool stackEmpty(struct stack* p_stack){
    if(p_stack->size == 0){
        return true;
    }

    return false;
}

int max(int a, int b){
    return (a >= b) ? a : b;
}

//      5
//   /    \
//  5      5
// / \      \
//5   5      5

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){

}

int main(void)
{
    struct TreeNode binaryTree[6];
    struct TreeNode *root = &binaryTree[0];

    //Input: root = [5,1,5,5,5,null,5]
    //Output: 4

    binaryTree[0].val = 5;
    binaryTree[1].val = 5;
    binaryTree[2].val = 5;
    binaryTree[3].val = 5;
    binaryTree[4].val = 5;
    binaryTree[5].val = 5;


    binaryTree[0].left = &binaryTree[1];
    binaryTree[0].right = &binaryTree[2];

    binaryTree[1].left = &binaryTree[3];
    binaryTree[1].right = &binaryTree[4];

    binaryTree[2].left = NULL;
    binaryTree[2].right = &binaryTree[5];

    binaryTree[3].left = NULL;
    binaryTree[3].right = NULL;

    binaryTree[4].left = NULL;
    binaryTree[4].right = NULL;

    binaryTree[5].left = NULL;
    binaryTree[5].right = NULL;

    int result = countUnivalSubtrees(root);

    printf("result = %d\n", result);

    return 0;
}

