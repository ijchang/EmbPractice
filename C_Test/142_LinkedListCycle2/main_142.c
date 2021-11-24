#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle.
//Note that pos is not passed as a parameter.
//Do not modify the linked list.


//Input: head = [3,2,0,-4], pos = 1
//Output: tail connects to node index 1
//Explanation: There is a cycle in the linked list, where tail connects to the second node.


//Constraints:

//The number of the nodes in the list is in the range [0, 10^4].
//-10^5 <= Node.val <= 10^5
//pos is -1 or a valid index in the linked-list.


//Follow up: Can you solve it using O(1) (i.e. constant) memory?


//Definition for singly-linked list.
struct ListNode {
 int val;
 struct ListNode *next;
};

//struct List{
//    struct ListNode *p_head;
//    struct ListNode *p_tail;
//}

struct ListNode *detectCycle(struct ListNode *head) {
    bool hasCycle = 0;
    struct ListNode *p_fast = head;
    struct ListNode *p_slow = head;
    struct ListNode *p_intersect = NULL;

    //======== phase1: check if there is cycle and get the intersection point =========
    if(head == NULL){
        hasCycle = 0;
        return NULL;
    }

    do{
        //p_fast run 2 steps at a time
        p_fast = p_fast->next;
        if(p_fast == NULL){
            break;
        }
        else{
            p_fast = p_fast->next;
            if(p_fast == NULL){
                break;
            }
        }
        //p_slow run 1 step at a time
        p_slow = p_slow->next;
    }while(p_fast != p_slow);

    if((p_fast != NULL) && (p_fast == p_slow)){
        hasCycle = 1;
        p_intersect = p_fast;
    }

    if(hasCycle == 0){
        return NULL;
    }
    else{
        //======== phase2: find the entry point of the cycle =========
        struct ListNode *p_start = head;

        while(p_start != p_intersect){
            p_start = p_start->next;
            p_intersect = p_intersect->next;
        }

        return p_start;
    }
}


//1 --> 2
//^      |
//|      |
//-------

int main(void)
{
    struct ListNode list[2] = {0};

    //Input: head = [3,2,0,-4], pos = 1
    //Output: true
    //Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    list[0].val = 1;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[0];

//    list[2].val = 0;
//    list[2].next = &list[3];
//
//    list[3].val = -4;
//    list[3].next = &list[2];

    struct ListNode *p_entry = detectCycle(&list[0]);

    if(p_entry == NULL){
        printf("isCycled=0\n");
    }
    else{
        printf("isCycled=1, entry=%d\n", p_entry->val);
    }

    return 0;
}



