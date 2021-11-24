#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

//Input: root = [3,9,20,null,null,15,7]
//Output: [[3],[9,20],[15,7]]

//Input: root = [1]
//Output: [[1]]

//Input: root = []
//Output: []

//The number of nodes in the tree is in the range [0, 2000].
//-1000 <= Node.val <= 1000


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

#define CAPACITY 2000

#define ASSERT(condition) while(!(condition)){};

struct queueEle{
    struct TreeNode *p_treeNode;
    int level;
};

struct queue{
    int size;
    int head;
    int tail;
    struct queueEle ele[CAPACITY];
};

void enqueue(struct queue *p_queue, struct TreeNode *p_treeNode, int level)
{
    if(p_queue->size == CAPACITY){
        return;
    }

    p_queue->tail = (p_queue->tail + 1) % CAPACITY;
    p_queue->ele[p_queue->tail].p_treeNode = p_treeNode;
    p_queue->ele[p_queue->tail].level = level;
    p_queue->size++;

    return;
}

struct TreeNode* dequeue(struct queue *p_queue, int* level){
    if(p_queue->size == 0){
        *level = INT_MIN;
        return NULL;
    }

    struct TreeNode* p_treeNode = p_queue->ele[p_queue->head].p_treeNode;
    *level = p_queue->ele[p_queue->head].level;

    p_queue->head = (p_queue->head + 1) % CAPACITY;
    p_queue->size--;

    return p_treeNode;
}

bool queueEmpty(struct queue *p_queue){
    if(p_queue->size == 0){
        return true;
    }
    else{
        return false;
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){

    if(root == NULL){
        *returnColumnSizes = NULL;
        *returnSize = 0;
        return NULL;
    }


    int nextLevel = 0;
    int** p_array = malloc(1*sizeof(int*));
    int* p_columnSizes = calloc(1, sizeof(int));
    int* p_subArray = malloc(1*sizeof(int));

    p_array[0] = p_subArray;

    struct queue dataQueue;
    dataQueue.size = 0;
    dataQueue.head = 0;
    dataQueue.tail = CAPACITY - 1;
    enqueue(&dataQueue, root, nextLevel);

    while(queueEmpty(&dataQueue) == false){
        int currLevel;
        int column;

        struct TreeNode* root = dequeue(&dataQueue, &currLevel);
//        printf("val = %d, level = %d\n", root->val, currLevel);

//p_columnSizes->[1, 2, 2]
//p_array->[[3],[9,20],[15,7]]
//          ^
//          p_subArray

        int* p_tmpSubArray = p_array[currLevel];
        ASSERT(p_tmpSubArray != NULL);
        int tmpColumnSize = p_columnSizes[currLevel];

        printf("== reallocSubArray, size=%d, level=%d\n", (tmpColumnSize+1), currLevel);
        p_tmpSubArray = realloc(p_tmpSubArray, (tmpColumnSize+1)*sizeof(int));
        printf("dbg\n");
        ASSERT(p_tmpSubArray != NULL);
        ASSERT(root != NULL);
        p_array[currLevel] = p_tmpSubArray;
        p_tmpSubArray[tmpColumnSize] = root->val;
        printf("array[%d][%d] = %d\n", currLevel, tmpColumnSize, root->val);
        p_columnSizes[currLevel]++;
        printf("columnSize[%d] = %d\n", currLevel, p_columnSizes[currLevel]);

        if((root->left != NULL) || (root->right != NULL)){
            if(root->left != NULL){
                enqueue(&dataQueue, root->left, currLevel+1);
            }

            if(root->right != NULL){
                enqueue(&dataQueue, root->right, currLevel+1);
            }

            if(currLevel == nextLevel){
                nextLevel++;
                printf("======reallocArray, size=%d\n", (nextLevel+1));
                p_array = realloc(p_array, (nextLevel+1)*sizeof(int*));
                int* p_subArray = malloc(1*sizeof(int));
                p_array[nextLevel] = p_subArray;
                printf("======reallocColumnSizes, size=%d\n\n\n\n", (nextLevel+1));
                p_columnSizes = realloc(p_columnSizes, (nextLevel+1)*sizeof(int));
                p_columnSizes[nextLevel] = 0;
            }
        }
    }

    *returnSize = nextLevel+1;
    *returnColumnSizes = p_columnSizes;
    return p_array;
}


int main(void)
{
    struct TreeNode binaryTree[5];

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

    int returnSize;
    int* returnColumnSizes;

    int**array = levelOrder(&binaryTree[0], &returnSize, &returnColumnSizes);

    printf("returnSize = %d\n", returnSize);

    for(int i = 0; i < returnSize; i++){
        printf("====== level%d====\n", i);
        for(int j = 0; j < returnColumnSizes[i]; j++){
            printf("val = %d\n", array[i][j]);
        }
    }
    return 0;
}



