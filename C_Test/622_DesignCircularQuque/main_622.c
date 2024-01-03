#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Design your implementation of the circular queue.
//The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out)
//principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".
//One of the benefits of the circular queue is that we can make use of the spaces in front of the queue.
//In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space
//in front of the queue. But using the circular queue, we can use the space to store new values.

//Implementation the MyCircularQueue class:

//MyCircularQueue(k) Initializes the object with the size of the queue to be k.
    //int Front() Gets the front item from the queue. If the queue is empty, return -1.
    //int Rear() Gets the last item from the queue. If the queue is empty, return -1.
    //boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
    //boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
    //boolean isEmpty() Checks whether the circular queue is empty or not.
    //boolean isFull() Checks whether the circular queue is full or not.
//You must solve the problem without using the built-in queue data structure in your programming language.

//Example 1:

//Input
//["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
//[[3], [1], [2], [3], [4], [], [], [], [4], []]
//Output
//[null, true, true, true, false, 3, true, true, true, 4]

//Constraints:

//1 <= k <= 1000
//0 <= value <= 1000
//At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.


typedef struct {
    int size;
    int capacity;
    int *nums;
    int head;//points to the front element if queue is not empty
    int tail;//points to the rear element if queue is not empty
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *p_obj = malloc(sizeof(MyCircularQueue));
    p_obj->nums = malloc(sizeof(int)*k);
    p_obj->size = 0;
    p_obj->capacity = k;
    p_obj->head = 0;
    p_obj->tail = p_obj->capacity - 1;

    return p_obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->size == obj->capacity){
        return false;
    }
    else{
        obj->tail = ((obj->tail + 1) == (obj->capacity)) ? 0 : (obj->tail + 1);
        obj->nums[obj->tail] = value;
        obj->size++;
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->size == 0){
        return false;
    }
    else{
        obj->head = ((obj->head + 1) == (obj->capacity)) ? 0 : (obj->head + 1);
        obj->size--;
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->size == 0){
        return -1;
    }
    else{
        return obj->nums[obj->head];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->size == 0){
        return -1;
    }
    else{
        return obj->nums[obj->tail];
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->size == obj->capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/


int main(void)
{
    //["MyCircularQueue","enQueue","Rear","Rear","deQueue","enQueue","Rear","deQueue","Front","deQueue","deQueue","deQueue"]
    //[[6],[6],[],[],[],[5],[],[],[],[],[],[]]
    //null,true,6,6,true,true,5,true,
    //null
    //true: 6
    //rear 6: 6
    //rear 6: 6
    //de true: null (head = 1, tail = 1)
    //en true: 5 (head = 1, tail = 2)
    //rear 5: 5
    //de true : null (head = tail = 2)
    //front -1:
    //[null,true,6,6,true,true,5,true,5,false,false,false]
    //[null,true,6,6,true,true,5,true,-1,false,false,false]


    MyCircularQueue* p_queue = myCircularQueueCreate(3);

    printf("%d, ", myCircularQueueEnQueue(p_queue, 1));
    printf("%d, ", myCircularQueueEnQueue(p_queue, 2));
    printf("%d, ", myCircularQueueEnQueue(p_queue, 3));
    printf("%d, ", myCircularQueueEnQueue(p_queue, 4));
    printf("%d, ", myCircularQueueRear(p_queue));
    printf("%d, ", myCircularQueueIsFull(p_queue));
    printf("%d, ", myCircularQueueDeQueue(p_queue));
    printf("%d, ", myCircularQueueEnQueue(p_queue, 4));
    printf("%d, ", myCircularQueueRear(p_queue));

    myCircularQueueFree(p_queue);

    return 0;
}



