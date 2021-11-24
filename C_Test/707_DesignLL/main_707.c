#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
//A node in a singly linked list should have two attributes: val and next. val is the value of the current node,
//and next is a pointer/reference to the next node.
//If you want to use the doubly linked list,
//you will need one more attribute prev to indicate the previous node in the linked list.
//Assume all nodes in the linked list are 0-indexed.

//Implement the MyLinkedList class:

//MyLinkedList() Initializes the MyLinkedList object.
//int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
//void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
//void addAtTail(int val) Append a node of value val as the last element of the linked list.
//void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
//void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

//Input
//["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
//[[], [1], [3], [1, 2], [1], [1], [1]]
//Output
//[null, null, null, null, 2, null, 3]

//Explanation
//MyLinkedList myLinkedList = new MyLinkedList();
//myLinkedList.addAtHead(1);
//myLinkedList.addAtTail(3);
//myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
//myLinkedList.get(1);              // return 2
//myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
//myLinkedList.get(1);              // return 3

//Constraints:
//0 <= index, val <= 1000
//Please do not use the built-in LinkedList library.
//At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

//Definition for Doubly-linked list.
typedef struct DListNode{
    int val;
    struct DListNode *next;
    struct DListNode *prev;
}DListNode_T;

typedef struct {
    DListNode_T *head;
    DListNode_T *tail;
    int length;
} MyLinkedList;

void printLL(MyLinkedList*obj){
    DListNode_T *p_currNode = obj->head;
    while(p_currNode != NULL){
        printf("%d->", p_currNode->val);
        p_currNode = p_currNode->next;
    }
    printf("NULL\n");
}

DListNode_T* getNode(MyLinkedList*obj, int index){
    DListNode_T *p_node = obj->head;
    if(p_node != NULL){
        for(int i = 0; i < index; i++){
            p_node = p_node->next;
            if(p_node == NULL){
                break;
            }
        }
    }

    return p_node;
}

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    printLL(list);

    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    DListNode_T* p_node = getNode(obj, index);
    if(p_node != NULL){
        printf("GetAtIdx %d, val=%d\n", index, p_node->val);
        return p_node->val;
    }
    printf("GetAtIdx %d, val=%d\n", index, -1);
    return -1;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    printf("AddAtHead, val=%d\n", val);
    DListNode_T* p_node = malloc(sizeof(DListNode_T));
    p_node->val = val;
    if(obj->head == NULL){
        p_node->prev = NULL;
        p_node->next = NULL;
        obj->head = p_node;
        obj->tail = p_node;
    }
    else{
        p_node->prev = NULL;
        p_node->next = obj->head;
        obj->head->prev = p_node;
        obj->head = p_node;
    }
    obj->length++;

    printLL(obj);
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    printf("AddAtTail, val=%d\n", val);
    DListNode_T* p_node = malloc(sizeof(DListNode_T));
    p_node->val = val;

    if(obj->tail == NULL){
        p_node->prev = NULL;
        p_node->next = NULL;
        obj->head = p_node;
        obj->tail = p_node;
    }
    else{
        p_node->prev = obj->tail;
        p_node->next = NULL;
        obj->tail->next = p_node;
        obj->tail = p_node;
    }

    obj->length++;

    printLL(obj);
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    printf("AddAtIdx %d, val=%d\n", index, val);

    DListNode_T *p_currNode = getNode(obj, index);
    if(p_currNode != NULL){
        DListNode_T *p_newNode = malloc(sizeof(DListNode_T));
        p_newNode->val = val;

        p_newNode->prev = p_currNode->prev;
        p_newNode->next = p_currNode;

        p_currNode->prev = p_newNode;
        if(p_newNode->prev != NULL){
            p_newNode->prev->next = p_newNode;
        }

        if(p_currNode == obj->head){
            obj->head = p_newNode;
        }
        obj->length++;
    }
    else{
        if(index == obj->length){
           myLinkedListAddAtTail(obj, val);
        }
    }

    printLL(obj);
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    printf("DeleteAtIdx %d\n", index);
    DListNode_T *p_currNode = getNode(obj, index);
    if(p_currNode != NULL){
        if(p_currNode->prev != NULL){
            p_currNode->prev->next = p_currNode->next;
        }

        if(p_currNode->next != NULL){
            p_currNode->next->prev = p_currNode->prev;
        }

        if(p_currNode == obj->tail){
            obj->tail = p_currNode->prev;
        }
        if(p_currNode == obj->head){
            obj->head = p_currNode->next;
        }

        obj->length--;
    }

    printLL(obj);
}

void myLinkedListFree(MyLinkedList* obj) {
    DListNode_T *p_currNode = obj->head;
    while(p_currNode != NULL){
        DListNode_T *p_tmpNode = p_currNode->next;
        free(p_currNode);
        p_currNode = p_tmpNode;
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);

 * myLinkedListAddAtHead(obj, val);

 * myLinkedListAddAtTail(obj, val);

 * myLinkedListAddAtIndex(obj, index, val);

 * myLinkedListDeleteAtIndex(obj, index);

 * myLinkedListFree(obj);
*/



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



