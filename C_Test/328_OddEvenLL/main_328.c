#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices,
//and return the reordered list.
//The first node is considered odd, and the second node is even, and so on.
//Note that the relative order inside both the even and odd groups should remain as it was in the input.
//You must solve the problem in O(1) extra space complexity and O(n) time complexity.


//Input: head = [1,2,3,4,5]
//Output: [1,3,5,2,4]

//Input: head = [2,1,3,5,6,4,7]
//Output: [2,3,6,7,1,5,4]

//Constraints:

//n == number of nodes in the linked list
//0 <= n <= 10^4
//-10^6 <= Node.val <= 10^6


//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};

//        1 --> 2 --> 3 --> 4 --> 5 --> 6
//        ^     ^
//      p_odd  p_even
//
//round1:
//        1 ---> 3 --> 4 --> 5 --> 6
//               ^
//             p_odd
//
//        2 ---> 4 --> 5 --> 6
//               ^
//             p_even
//
//round2:
//        1 ---> 3 --> 5 --> 6
//                      ^
//                    p_odd
//
//        2 ---> 4 --> 6
//                      ^
//                    p_even
//
//round3:
//        1 ---> 3 --> 5
//                              ^
//                            p_odd
//
//        2 ---> 4 --> 6
//                              ^
//                          p_even



struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }

    struct ListNode *p_oddPrev, *p_oddCurr;
    struct ListNode *p_even, *p_evenCurr;

    p_oddPrev = p_oddCurr = head;
    p_even = p_evenCurr = head->next;

//            1 --> 2

    while((p_oddCurr != NULL) && (p_evenCurr != NULL)){
        if(p_oddCurr->next != NULL){
            p_oddCurr->next = p_oddCurr->next->next;
        }
        p_oddPrev = p_oddCurr;
        p_oddCurr = p_oddCurr->next;

        if(p_evenCurr->next != NULL){
            p_evenCurr->next = p_evenCurr->next->next;
        }
        p_evenCurr = p_evenCurr->next;
    }

    if(p_oddCurr != NULL){
        p_oddCurr->next = p_even;
    }
    else{
        p_oddPrev->next = p_even;
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



