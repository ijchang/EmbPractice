#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val,
//and return the new head.


//Input: head = [1,2,6,3,4,5,6], val = 6
//Output: [1,2,3,4,5]

//Input: head = [], val = 1
//Output: []

//Input: head = [7,7,7,7], val = 7
//Output: []

//Constraints:

//The number of nodes in the list is in the range [0, 10^4].
//1 <= Node.val <= 50
//0 <= val <= 50


//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p_prev = NULL;
    struct ListNode *p_curr = head;

    if(head == NULL){
        return head;
    }

//    1 --> 1 --> 3 --> 4 --> NULL

    while(p_curr != NULL){
        if(p_curr->val == val){
            if(p_prev == NULL){//removing head
                head = p_curr->next;
                p_curr->next = NULL;
                p_curr = head;
            }
            else{//removing middle
                p_prev->next = p_curr->next;
                p_curr->next = NULL;
                p_curr = p_prev->next;
            }
        }
        else{
            p_prev = p_curr;
            p_curr = p_curr->next;
        }
    }

    return head;
}


int main(void)
{
    struct ListNode list[5] = {0};

    //Input: head = [3,2,0,-4], pos = 1
    //Output: true
    //Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 1;
    list[1].next = &list[2];

    list[2].val = 1;
    list[2].next = &list[3];

    list[3].val = 1;
    list[3].next = &list[4];

    list[4].val = 1;
    list[4].next = NULL;

//    list[2].val = 0;
//    list[2].next = &list[3];
//
//    list[3].val = -4;
//    list[3].next = &list[2];

    struct ListNode *p_head = removeElements(&list[0], 1);

    printf("[");
    while(p_head != NULL){
        printf("%d, ", p_head->val);
        p_head = p_head->next;
    }
    printf("]\n");

    return 0;
}



