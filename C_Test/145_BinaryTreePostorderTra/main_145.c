#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the root of a binary tree, return the postorder traversal of its nodes' values.

//Input: root = [1,null,2,3]
//Output: [3,2,1]


//Input: root = []
//Output: []


//Input: root = [1]
//Output: [1]


//The number of the nodes in the tree is in the range [0, 100].
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

void getVal(struct TreeNode* root, int *p_array)
{
    if(root == NULL){
        return;
    }

    getVal(root->left, p_array);

    getVal(root->right, p_array);

    *(p_array + size) = root->val;
    size++;


    return;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){

    size = 0;
    int *p_array = malloc(100*sizeof(int));

//recursive version
//    getVal(root, p_array);
//iterative version
    struct stack treeStack;
    treeStack.size = 0;
    treeStack.top = -1;

    do{
        if(root != NULL){
            pushStack(&treeStack, root);
            root = root->left;
        }
        else{
            root = popStack(&treeStack);//get parent
            if(root == NULL){
                break;
            }
            else{
                if(root->right == NULL){
                    *(p_array + size) = root->val;
                    size++;
                    root = root->right;
                }
                else{
                    struct TreeNode *tmpRoot;
                    tmpRoot = root->right;
                    root->right = NULL;
                    pushStack(&treeStack, root);
                    root = tmpRoot;
                }
            }
        }
    }while((stackEmpty(&treeStack) == false));


    *returnSize = size;
    return p_array;
}


int main(void)
{
    return 0;
}



