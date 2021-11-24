#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given a Circular Linked List node, which is sorted in ascending order,
//write a function to insert a value insertVal into the list such that it remains a sorted circular list.
//The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.
//If there are multiple suitable places for insertion, you may choose any place to insert the new value.
//After the insertion, the circular list should remain sorted.
//If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node.
//Otherwise, you should return the originally given node.


//Input: head = [3,4,1], insertVal = 2
//Output: [3,4,1,2]
//Explanation: In the figure above, there is a sorted circular list of three elements.
//You are given a reference to the node with value 3, and we need to insert 2 into the list.
//The new node should be inserted between node 1 and node 3.
//After the insertion, the list should look like this, and we should still return node 3.


//Constraints:

//0 <= Number of Nodes <= 5 * 104
//-10^6 <= Node.val, insertVal <= 10^6

//              30
// 1 -- > 10 --> 20  --> 1
//        ^
//        h
//20 --> 1 --> 10 --> 20

//  Definition for a Node.
struct Node {
    int val;
    struct Node *next;
};

struct Node* insert(struct Node* head, int insertVal) {
    if(head == NULL){
        struct Node* list = malloc(sizeof(struct Node));
        list->val = insertVal;
        list->next = list;
        return list;
    }
    else{
        struct Node *maxNode;
        struct Node *targetNode = NULL;
        int max;

        struct Node *node = head;
        max = head->val;
        maxNode = head;

        do{
            if(node->val >= max){
                max = node->val;
                maxNode = node;
            }

            if((insertVal >= node->val) && (insertVal <= node->next->val)){
                targetNode = node;
                break;
            }

            node = node->next;
        }while(node != head);

        if(targetNode != NULL){
            struct Node *newNode = malloc(sizeof(struct Node));
            newNode->val = insertVal;
            newNode->next = targetNode->next;
            targetNode->next = newNode;
        }
        else{
            struct Node *newNode = malloc(sizeof(struct Node));
            targetNode = maxNode;
            newNode->val = insertVal;
            newNode->next = targetNode->next;
            targetNode->next = newNode;
        }

        return head;
    }
}


int main(void)
{
    struct Node list[4] = {0};

    //Input: head = [3,2,0,-4], pos = 1
    //Output: true
    //Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 5;
    list[1].next = &list[2];

    list[2].val = 7;
    list[2].next = &list[3];

    list[3].val = 8;
    list[3].next = &list[0];

    struct Node *p_list = insert(&list[0], 3);
    struct Node *head = p_list;

    do{
        printf("%d->", p_list->val);
        p_list = p_list->next;
    }while(p_list != head);
    printf("\n");
    return 0;
}



