#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given the root of a binary tree and an integer targetSum,
//return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

//A leaf is a node with no children.


//Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
//Output: true


//Input: root = [1,2,3], targetSum = 5
//Output: false

//Input: root = [1,2], targetSum = 0
//Output: false


//The number of nodes in the tree is in the range [0, 5000].
//-1000 <= Node.val <= 1000
//-1000 <= targetSum <= 1000


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

//          1
//         / \
//        /   \
//       /     \
//      /       \
//     2         2
//    / \       / \
//   /   \     /   \
//  3     4   4     3
// / \   / \ / \   / \
//5   6 7  8 8  7 6   5


bool hasPathSum(struct TreeNode* root, int targetSum){
    if((root == NULL)){
        return false;
    }

    if((root->left == NULL) && (root->right == NULL)){
        if((targetSum - root->val) == 0){
            return true;
        }
        else{
            return false;
        }
    }

    int initialSum = targetSum - root->val;
    bool leftHasSum = false;
    bool rightHasSum = false;

    if(root->left != NULL){
        leftHasSum = hasPathSum(root->left, initialSum);
    }

    if(root->right != NULL){
        rightHasSum = hasPathSum(root->right, initialSum);
    }

    return (leftHasSum || rightHasSum);
}

int main(void)
{
    struct TreeNode binaryTree[7];
    struct TreeNode *root = &binaryTree[0];

    binaryTree[0].val = 1;
    binaryTree[1].val = 2;
    binaryTree[2].val = 2;
    binaryTree[3].val = 3;
    binaryTree[4].val = 4;
    binaryTree[5].val = 4;
    binaryTree[6].val = 3;


    binaryTree[0].left = &binaryTree[1];
    binaryTree[0].right = &binaryTree[2];

    binaryTree[1].left = &binaryTree[3];
    binaryTree[1].right = &binaryTree[4];

    binaryTree[2].left = &binaryTree[5];
    binaryTree[2].right = &binaryTree[6];

    binaryTree[3].left = NULL;
    binaryTree[3].right = NULL;

    binaryTree[4].left = NULL;
    binaryTree[4].right = NULL;

    binaryTree[5].left = NULL;
    binaryTree[5].right = NULL;

    binaryTree[6].left = NULL;
    binaryTree[6].right = NULL;

    bool result = hasPathSum(root, 3);

    printf("result = %d\n", result);

    return 0;
}

