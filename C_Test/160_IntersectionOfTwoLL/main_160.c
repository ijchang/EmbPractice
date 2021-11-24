#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
//If the two linked lists have no intersection at all, return null.

//The test cases are generated such that there are no cycles anywhere in the entire linked structure.
//Note that the linked lists must retain their original structure after the function returns.

//Custom Judge:
//The inputs to the judge are given as follows (your program is not given these inputs):
    //intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
    //listA - The first linked list.
    //listB - The second linked list.
    //skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
    //skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.

//The judge will then create the linked structure based on these inputs and pass the two heads,
//headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

//Example:
//Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
//Output: Intersected at '8'
//Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
//From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A;
//There are 3 nodes before the intersected node in B.

//Constraints:
    //The number of nodes of listA is in the m.
    //The number of nodes of listB is in the n.
    //0 <= m, n <= 3 * 10^4
    //1 <= Node.val <= 10^5
    //0 <= skipA <= m
    //0 <= skipB <= n
    //intersectVal is 0 if listA and listB do not intersect.
    //intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.

//Follow up: Could you write a solution that runs in O(n) time and use only O(1) memory?


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 1 -- 2 -- 3 -- 4 -- 5 -- 6
                /
               9
              /
            10

1 -- 2 -- 3 -- 4 -- 5 -- 6

10 -- 9 -- 8 -- 7



struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

}

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



