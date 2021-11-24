#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


//Input: root = [1,2,2,3,4,4,3]
//Output: true


//Input: root = [1,2,2,null,3,null,3]
//Output: false


//The number of nodes in the tree is in the range [1, 1000].
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


bool isMirror(struct TreeNode* root1, struct TreeNode* root2){

    if((root1 == NULL) && (root2 == NULL)){
        return true;
    }

    if((root1 == NULL) || (root2 == NULL)){
        return false;
    }

    bool cond1 = (root1->val == root2->val);
    bool cond2 = isMirror(root1->right, root2->left);
    bool cond3 = isMirror(root1->left, root2->right);

    if(cond1 && cond2 && cond3){
        return true;
    }
    else{
        return false;
    }
}

bool isSymmetric(struct TreeNode* root){
//===== recursive method =======
//Time complexity: O(N)
//Space complexity: O(N) (ie, height of the tree. The worst case is a linear tree)

//    return isMirror(root, root);

//===== Iterative method =======

    if(root == NULL){
        return true;
    }

    int retVal = true;

    if((root->left == NULL) && (root->right == NULL)){
        return true;
    }

    if((root->left == NULL) || (root->right == NULL)){
        return false;
    }

    if(root->left->val != root->right->val){
        return false;
    }

    struct stack *p_treeStack = stackCreate();

    struct stackEntry *p_stackEntry1 = malloc(sizeof(struct stackEntry));
        p_stackEntry1->p_treeNode = root->left;
        printf("push %d\n", root->left->val);
        stackPush(p_treeStack, p_stackEntry1);
    struct stackEntry *p_stackEntry2 = malloc(sizeof(struct stackEntry));
        p_stackEntry2->p_treeNode = root->right;
        printf("push %d\n", root->right->val);
        stackPush(p_treeStack, p_stackEntry2);

    while(stackEmpty(p_treeStack) == false){
        struct stackEntry *p_entry1, *p_entry2;

        printf("loop\n");
        p_entry1 = stackPop(p_treeStack);
        printf("    pop %d\n", (p_entry1->p_treeNode == NULL) ? (-1) : (p_entry1->p_treeNode->val));
        p_entry2 = stackPop(p_treeStack);
        printf("    pop %d\n", (p_entry2->p_treeNode == NULL) ? (-1) : (p_entry2->p_treeNode->val));

        if((p_entry1->p_treeNode == NULL) && (p_entry2->p_treeNode == NULL)){
            continue;
        }

        if((p_entry1->p_treeNode == NULL) || (p_entry2->p_treeNode == NULL)){
            retVal = false;
            break;
        }

        bool cond1 = ((p_entry1->p_treeNode->val) == (p_entry2->p_treeNode->val));
        if(cond1 == false){
            retVal = false;
            break;
        }

        struct stackEntry *p_stackEntry1 = malloc(sizeof(struct stackEntry));
            p_stackEntry1->p_treeNode = p_entry1->p_treeNode->left;
            printf("push %d\n", (p_stackEntry1->p_treeNode == NULL) ? (-1) : p_stackEntry1->p_treeNode->val);
            stackPush(p_treeStack, p_stackEntry1);
        struct stackEntry *p_stackEntry2 = malloc(sizeof(struct stackEntry));
            p_stackEntry2->p_treeNode = p_entry2->p_treeNode->right;
            printf("push %d\n", (p_stackEntry2->p_treeNode == NULL) ? (-1) : p_stackEntry2->p_treeNode->val);
            stackPush(p_treeStack, p_stackEntry2);

        p_stackEntry1 = malloc(sizeof(struct stackEntry));
            p_stackEntry1->p_treeNode = p_entry1->p_treeNode->right;
            printf("push %d\n", (p_stackEntry1->p_treeNode == NULL) ? (-1) : p_stackEntry1->p_treeNode->val);
            stackPush(p_treeStack, p_stackEntry1);
        p_stackEntry2 = malloc(sizeof(struct stackEntry));
            p_stackEntry2->p_treeNode = p_entry2->p_treeNode->left;
            printf("push %d\n", (p_stackEntry2->p_treeNode == NULL) ? (-1) : p_stackEntry2->p_treeNode->val);
            stackPush(p_treeStack, p_stackEntry2);

        free(p_entry1);
        free(p_entry2);
    }

    free(p_treeStack);

    return retVal;
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

    bool mirror = isSymmetric(root);

    printf("mirror = %d\n", mirror);

    return 0;
}

