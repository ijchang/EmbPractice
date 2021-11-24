#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the head of a singly linked list, reverse the list, and return the reversed list.

//Input: head = [1,2,3,4,5]
//Output: [5,4,3,2,1]

//Input: head = []
//Output: []

//Constraints:

//The number of nodes in the list is the range [0, 5000].
//-5000 <= Node.val <= 5000



//Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?



//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){

    //Approach 1: Iterative
//                         1 --> 2 --> 3 --> NULL
//        step1:     2 --> 1  -------> 3 --> NULL
//step2:       3 --> 2 --> 1  -------------> NULL

//    if(head == NULL){
//        return NULL;
//    }
//
//    struct ListNode *p_tail = head;
//    struct ListNode *p_curr;
//    while(head->next != NULL){
//        p_curr = head->next;
//        head->next = p_curr->next;
//        p_curr->next = p_tail;
//        p_tail = p_curr;
//    }
//
//    return p_tail;

    //Approach2: Recursion
//               1 --> 2 --> 3 --> NULL
//step1:      1 --> 2 <-- 3
//                  >null
//step2:      1 <-- 2 <-- 3
//            >null >null
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }

        struct ListNode* p_head = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return p_head;
    }

//reverse(1->next)
//    3 = reverse(2->next)
//        return 3;
//    3->next = 2;
//    2->next = NULL;
//    return 3;
//2->next = 1;
//1->next = NULL;

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

    struct ListNode *p_head = reverseList(&list[0]);

    printf("[");
    while(p_head != NULL){
        printf("%d, ", p_head->val);
        p_head = p_head->next;
    }
    printf("]\n");

    return 0;
}



