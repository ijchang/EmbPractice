#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the head of a linked list, remove the nth node from the end of the list and return its head.

//Input: head = [1,2,3,4,5], n = 2
//Output: [1,2,3,5]

//Input: head = [1], n = 1
//Output: []

//Input: head = [1,2], n = 1
//Output: [1]

//Constraints:

//The number of nodes in the list is sz.
    //1 <= sz <= 30
    //0 <= Node.val <= 100
    //1 <= n <= sz


//Follow up: Could you do this in one pass?

//1 -- 2 -- 3 -- 4 -- 5 -- 6 -- 7


//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    //Approach 1: Two pointers
//    struct ListNode *p_lead = head;
//    struct ListNode *p_left = head;
//    struct ListNode *p_prevOfleft = NULL;
//
//    if(head == NULL){
//        return NULL;
//    }
//
//    for(int i = 0; i < n; i++){
//        p_lead = p_lead->next;
//    }
//
//    while(p_lead != NULL){
//        p_lead = p_lead->next;
//        p_prevOfleft = p_left;
//        p_left = p_left->next;
//    }
//
//    //when p_lead is NULL, p_left is pointing to the node we'd like to delete
//    if(p_prevOfleft == NULL){//means the 1st node is what we want to delete
//        return p_left->next;
//    }
//    else{
//        struct ListNode *p_nextOfLeft = p_left->next;
//        p_prevOfleft->next = p_nextOfLeft;
//        return head;
//    }

    //Apporach 2: Remove (L - n + 1)th node
    //first count how many nodes in the list
    int length = 0;
    struct ListNode *p_count = head;

    if(head == NULL){
        return NULL;
    }

    while(p_count != NULL){
        length++;
        p_count = p_count->next;
    }

    int step = (length - n);//means how many steps we need to traverse before we can get to the node we want to delete
    int count = 0;
    struct ListNode *p_prev = NULL;
    p_count = head;

    for(int i = 0; i < step; i++){
        p_prev = p_count;
        p_count = p_count->next;
    }

    if(p_prev == NULL){
        return p_count->next;
    }
    else{
        p_prev->next = p_count->next;
        return head;
    }
}


int main(void)
{
    struct ListNode list[5] = {0};

    //Input: head = [3,2,0,-4], pos = 1
    //Output: true
    //Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 3;
    list[2].next = &list[3];

    list[3].val = 4;
    list[3].next = &list[4];

    list[4].val = 5;
    list[4].next = NULL;

//    list[2].val = 0;
//    list[2].next = &list[3];
//
//    list[3].val = -4;
//    list[3].next = &list[2];

    struct ListNode *p_head = removeNthFromEnd(&list[0], 2);

    printf("[");
    while(p_head != NULL){
        printf("%d, ", p_head->val);
        p_head = p_head->next;
    }
    printf("]\n");

    return 0;
}



