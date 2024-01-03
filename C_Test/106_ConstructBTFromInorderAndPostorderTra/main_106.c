#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
#include "limits.h"

//Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and
//postorder is the postorder traversal of the same tree, construct and return the binary tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//Output: [3,9,20,null,null,15,7]

//        3
//       / \
//      9   20
//     /   /  \
//    11  15   7
//   /   /  \   \
//  13  17   18  10

//1st Round:
// find the roo->val in postorder. Use it to find the rightArray, and leftArray in inorder
// root->val = postorder[postorderSize - 1];
// inorder = [13,11,9,3,17,15,18,20,7,10], postorder = [13,11,9,17,18,15,10,7,20,3]
//                    ^

//rootIdx = findRootIdx(rootVal, inorder);//find where root is in the inorder array
int findRootIdx(int rootVal, int* inorder, int inorderSize){
  for(int idx = 0; idx < inorderSize; idx++){
      if(rootVal == inorder[idx]){
          return idx;
      }
  }
  return -1;
}

#define ASSERT(cond, id) while(!cond){printf("ASSERT! id=%d\n",id);}

//The idea of the solution is basically using recursion(divide and conquer):
//1. Use postorder's last element to get the root
//2. Use the root->val to identify its array idx in inorder array. Then you have right part and left part of the whole tree
//3. Use the right part and (postorderSize-1) as new inputs to buildSubTree function again
//4. Use the left part and (postorderSize-1-rightSize) as new inputs to buildSubTree function again


struct TreeNode* buildSubTree(int* inorder, int inorderSize, int* postorder, int postorderSize){

    struct TreeNode *root = NULL;
    struct TreeNode *leftTree = NULL;
    struct TreeNode *rightTree = NULL;
    root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize - 1];
    int rootIdx = findRootIdx(root->val, inorder, inorderSize);//find where root is in the inorder array
    //int rootIdx = hashInorder[root->val];
    int rightArrayStartIdx = rootIdx + 1;
    int rightArrayEndIdx = inorderSize - 1;
    bool rightArray = (rightArrayStartIdx <= rightArrayEndIdx) ? true : false;

    int leftArrayStartIdx = 0;
    int leftArrayEndIdx = rootIdx - 1;
    bool leftArray = ((rootIdx - 1) >= 0) ? true : false;

    int rightArraySize = 0;
    postorderSize--;
    if(rightArray){
        rightArraySize = rightArrayEndIdx - rightArrayStartIdx + 1;
        int* tmpInorder = malloc(rightArraySize*sizeof(int));
        for(int idx = 0; idx < rightArraySize; idx++){
            tmpInorder[idx] = inorder[rightArrayStartIdx + idx];
        }
        rightTree = buildSubTree(tmpInorder, rightArraySize, postorder, postorderSize);
        free(tmpInorder);
    }

    if(leftArray){
//    Use rightArray's first element to find its index in postorder, postOrderLastIdx=index-1
        postorderSize -= rightArraySize;

        int leftArraySize = leftArrayEndIdx - leftArrayStartIdx + 1;
        int* tmpInorder = malloc(leftArraySize*sizeof(int));
        for(int idx = 0; idx < leftArraySize; idx++){
            tmpInorder[idx] = inorder[leftArrayStartIdx + idx];
        }
        leftTree = buildSubTree(tmpInorder, leftArraySize, postorder, postorderSize);
        free(tmpInorder);
    }

    root->left = leftTree;
    root->right = rightTree;
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(postorderSize == 0){
        return NULL;
    }

    //======== construct the hash map ========
    //for(int idx = 0; idx < inorderSize; idx++){
    //    hashInorder[inorder[idx]] = idx;
    //}

    return buildSubTree(inorder, inorderSize, postorder, postorderSize);

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

