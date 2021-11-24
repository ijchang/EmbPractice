#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//You are given two non-empty linked lists representing two non-negative integers.
//The digits are stored in reverse order, and each of their nodes contains a single digit.
//Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.

//Input: l1 = [2,4,3], l2 = [5,6,4]
//Output: [7,0,8]
//Explanation: 342 + 465 = 807.

//Input: l1 = [0], l2 = [0]
//Output: [0]

//Constraints:

//The number of nodes in each linked list is in the range [1, 100].
//0 <= Node.val <= 9
//It is guaranteed that the list represents a number that does not have leading zeros.


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *prev = NULL;
    struct ListNode *head = NULL;

    int carry = 0;

    while((l1 != NULL) || (l2 != NULL) || (carry == 1)){
        struct ListNode *l3 = malloc(sizeof(struct ListNode));
        l3->next = NULL;

        int a = 0;
        int b = 0;
        int sum = 0;

        if(prev != NULL){
            prev->next = l3;
        }
        else{
            head = l3;
        }
        prev = l3;

        if(l1 != NULL){
            a = l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL){
            b = l2->val;
            l2 = l2->next;
        }

        sum = a + b + carry;
        if(sum >= 10){
            l3->val = sum - 10;
            carry = 1;
        }
        else{
            l3->val = sum;
            carry = 0;
        }
    }

    return head;
}

int main(void)
{
    struct ListNode list[4] = {0};

    //Input: head = [3,2,0,-4], pos = 1
    //Output: true
    //Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    list[0].val = 3;
    list[0].next = &list[1];

    list[1].val = 7;
    list[1].next = &list[2];

    list[2].val = 0;
    list[2].next = &list[3];

    list[3].val = 7;
    list[3].next = NULL;//&list[1];

    struct ListNode* l3 = addTwoNumbers(&list[0], &list[0]);

    while(l3 != NULL){
        printf("%d->", l3->val);
        l3 = l3->next;
    }
    printf("NULL\n");

    return 0;
}



