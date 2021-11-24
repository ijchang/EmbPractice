#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
//Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.

//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

//Constaints
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

bool hasCycle(struct ListNode *head) {
    bool retVal = 0;
    struct ListNode *p_fast = head;
    struct ListNode *p_slow = head;

    if(head == NULL){
        return retVal;
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
        retVal = 1;
    }

    return retVal;
}


int main(void)
{
    struct ListNode list[4] = {0};

    //Input: head = [3,2,0,-4], pos = 1
    //Output: true
    //Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

    list[0].val = 3;
    list[0].next = &list[1];

    list[1].val = 2;
    list[1].next = &list[2];

    list[2].val = 0;
    list[2].next = &list[3];

    list[3].val = -4;
    list[3].next = NULL;//&list[1];

    bool isCycled = hasCycle(&list[0]);

    printf("isCycled=%d\n", isCycled);

    return 0;
}



