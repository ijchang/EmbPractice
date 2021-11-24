#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the head of a singly linked list, return true if it is a palindrome.


//Input: head = [1,2,2,1]
//Output: true

//Input: head = [1,2]
//Output: false

//Constraints:

///The number of nodes in the list is in the range [1, 10^5].
//0 <= Node.val <= 9

//Follow up: Could you do it in O(n) time and O(1) space?


//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){

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
    list[2].next = NULL;//&list[3];

    list[3].val = 4;
    list[3].next = &list[4];

    list[4].val = 5;
    list[4].next = NULL;

//    list[2].val = 0;
//    list[2].next = &list[3];
//
//    list[3].val = -4;
//    list[3].next = &list[2];

    struct ListNode *p_head = oddEvenList(&list[0]);

    printf("[");
    while(p_head != NULL){
        printf("%d, ", p_head->val);
        p_head = p_head->next;
    }
    printf("]\n");

    return 0;
}



