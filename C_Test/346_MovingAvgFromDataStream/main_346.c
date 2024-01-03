#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//Implement the MovingAverage class:
//MovingAverage(int size) Initializes the object with the size of the window size.
//double next(int val) Returns the moving average of the last size values of the stream.


//Input
//["MovingAverage", "next", "next", "next", "next"]
//[[3], [1], [10], [3], [5]]
//Output
//[null, 1.0, 5.5, 4.66667, 6.0]

//Constraints:

//1 <= size <= 1000
//-10^5 <= val <= 10^5
//At most 10^4 calls will be made to next.


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

typedef struct {
    MyCircularQueue *p_queue;
    double lastSum;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    MovingAverage *p_mov = malloc(sizeof(MovingAverage));
    p_mov->p_queue = myCircularQueueCreate(size);
    p_mov->lastSum = 0;
    return p_mov;
}

double movingAverageNext(MovingAverage* obj, int val) {
    double avg = obj->lastSum;

    if(myCircularQueueIsFull(obj->p_queue) == true){
        avg -= myCircularQueueFront(obj->p_queue);
        myCircularQueueDeQueue(obj->p_queue);
    }
    myCircularQueueEnQueue(obj->p_queue, val);
    avg += (double)val;
    obj->lastSum = avg;
    avg /= (double)obj->p_queue->size;

    return avg;
}

void movingAverageFree(MovingAverage* obj) {
    myCircularQueueFree(obj->p_queue);
    free(obj);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);

 * movingAverageFree(obj);
*/


int main(void)
{
    //Input
    //["MovingAverage", "next", "next", "next", "next"]
    //[[3], [1], [10], [3], [5]]
    //Output
    //[null, 1.0, 5.5, 4.66667, 6.0]

    MovingAverage* p_mov = movingAverageCreate(3);

    printf("%f, ", movingAverageNext(p_mov, 1));
    printf("%f, ", movingAverageNext(p_mov, 10));
    printf("%f, ", movingAverageNext(p_mov, 3));
    printf("%f, ", movingAverageNext(p_mov, 5));

    movingAverageFree(p_mov);

    return 0;
}



