#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given the root of a binary tree, return the number of uni-value subtrees.
//A uni-value subtree means all nodes of the subtree have the same value.


//Input: root = [5,1,5,5,5,null,5]
//Output: 4


//Input: root = []
//Output: 0


//Input: root = [5,5,5,5,5,null,5]
//Output: 6


//The numbrt of the node in the tree will be in the range [0, 1000].
//-1000 <= Node.val <= 1000

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

int numOfUniValSubTree;

bool isSubtreeUnique(struct TreeNode* root){
    if((root->left == NULL) && (root->right == NULL)){
        numOfUniValSubTree++;
        return true;
    }

    bool cond1 = (root->left == NULL) ? true : isSubtreeUnique(root->left);
    bool cond2 = (root->right == NULL) ? true : isSubtreeUnique(root->right);
    bool cond3 = true;

    if((root->left != NULL) && (root->right != NULL)){
        cond3 = (root->left->val == root->right->val) && (root->val == root->left->val);
    }
    else if((root->left != NULL) && (root->right == NULL)){
        cond3 = (root->val == root->left->val);
    }
    else if((root->right != NULL) && (root->left == NULL)){
        cond3 = (root->val == root->right->val);
    }

    if(cond1 && cond2 && cond3){
        numOfUniValSubTree++;
        return true;
    }

    return false;
}

int countUnivalSubtrees(struct TreeNode* root){

    numOfUniValSubTree = 0;

    if(root == NULL){
        return 0;
    }

    isSubtreeUnique(root);

    return numOfUniValSubTree;
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

