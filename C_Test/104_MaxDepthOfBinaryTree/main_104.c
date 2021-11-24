#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given the root of a binary tree, return its maximum depth.

//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


//Input: root = [3,9,20,null,null,15,7]
//Output: 3

//Input: root = [1,null,2]
//Output: 2

//Input: root = []
//Output: 0

//Input: root = [0]
//Output: 1

//The number of nodes in the tree is in the range [0, 104].
//-100 <= Node.val <= 100


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
    return p_tmpEntry;
}

void stackPush(struct stack* p_stack, struct stackEntry* p_stackEntry){
    if(p_stack->size == CAPACITY){
        return;
    }
    p_stackEntry->p_pre = p_stack->p_top;
    p_stack->p_top = p_stackEntry;
    p_stack->size++;
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

int maxDepth(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }

//===== Iterative method =========
//Time complexity: O(N)
//Space complexity: O(log2(N))

/*
    int maxDepth = 1;
    struct stack* p_treeStack = stackCreate();

    struct stackEntry *p_stackEntry = malloc(sizeof(struct stackEntry));
    p_stackEntry->p_treeNode = root;
    p_stackEntry->depth = 1;
    stackPush(p_treeStack, p_stackEntry);

    while(stackEmpty(p_treeStack) == false){
        struct stackEntry *p_currEntry = stackPop(p_treeStack);
        ASSERT(p_currEntry != NULL);

        if(p_currEntry->depth > maxDepth){
            maxDepth = p_currEntry->depth;
        }

        if(p_currEntry->p_treeNode->left != NULL){
            int depth = p_currEntry->depth;

            struct stackEntry *p_stackEntry = malloc(sizeof(struct stackEntry));
            p_stackEntry->p_treeNode = p_currEntry->p_treeNode->left;
            p_stackEntry->depth = depth + 1;
            stackPush(p_treeStack, p_stackEntry);
        }

        if(p_currEntry->p_treeNode->right != NULL){
            int depth = p_currEntry->depth;

            struct stackEntry *p_stackEntry = malloc(sizeof(struct stackEntry));
            p_stackEntry->p_treeNode = p_currEntry->p_treeNode->right;
            p_stackEntry->depth = depth + 1;
            stackPush(p_treeStack, p_stackEntry);
        }

        free(p_currEntry);
    }

    free(p_treeStack);
*/

//====== Recursion method ===========
//Time complexity: O(N)
//Space complexity: O(log2(N))

    return 1 + max(maxDepth(root->left), maxDepth(root->right));

//====== BFS methods =========
//TBD

}


int main(void)
{
    struct TreeNode binaryTree[5];
    struct TreeNode *root = &binaryTree[0];

    binaryTree[0].val = 3;
    binaryTree[1].val = 9;
    binaryTree[2].val = 20;
    binaryTree[3].val = 15;
    binaryTree[4].val = 7;

    binaryTree[0].left = &binaryTree[1];
    binaryTree[0].right = &binaryTree[2];

    binaryTree[1].left = NULL;
    binaryTree[1].right = NULL;

    binaryTree[2].left = &binaryTree[3];
    binaryTree[2].right = &binaryTree[4];

    binaryTree[3].left = NULL;
    binaryTree[3].right = NULL;

    binaryTree[4].left = NULL;
    binaryTree[4].right = NULL;

    int depth = maxDepth(root);

    printf("depth = %d\n", depth);

    return 0;
}



