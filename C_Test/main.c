#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "limits.h"
//#include "myHeader.h"
//use gcc -fstrict-aliasing -Wstrict-aliasing=3 -O2 -o run.exe main.c to build
//The printf result is 2
//If -O2 is removed, the result is 128

//void memcpTmp(char* dst, char* src, int len){
//    while(len--){
//        *dst++ = *src++;
//    }
//}

void swap(int *p_nums, int i, int j){
    int tmp;
    tmp = p_nums[i];
    p_nums[i] = p_nums[j];
    p_nums[j] = tmp;
}

int partition(int *p_nums, int start, int end){
    int pivot, pIdx;

    //find pivot and its index pIdx
    pIdx = start + (end - start)/2;
    pivot = p_nums[pIdx];

    //arrange the array so that every elements to the left of the pIdx is less than or equal to pivot, and each elements
    //to the right of the pIdx is large than or equal to the pivot.
    int i = start-1;
    int j = end+1;
    while(1){
        //starting from the i+1, from left to right, keep searching for an element p_nums[i] which is larger than or equal to pviot.
        do{
            i++;
        }while(p_nums[i] < pivot);
       
        //starting from the j-1, from right to left, find a element p_nums[j] which is less than or equal to pviot
        do{
            j--;
        }while(p_nums[j] > pivot);

        //finish the process if i >= j; When this happens, all the elements to the right of i
        //is larger than pivot and all the elements to the left of i is smaller than pivot.
        if(i >= j){
            break;
        }
        //swap the two elements
        swap(p_nums, i, j);
    }
    
    return j;
}

void qSort(int *p_nums, int start, int end){
    int pIdx;

	if(start >= end){
		return;
	}
    
    pIdx = partition(p_nums, start, end);

    qSort(p_nums, start, pIdx);
    qSort(p_nums, pIdx+1, end);
}

static inline int foo(){
    return 2;
}

inline int add(int a, int b);

int main(void)
{
	int nums[6] = {0, 10, -5, 7, -3, -12};
	qSort(nums, 0, 5);
	for(int i = 0; i < 6; i++){
		printf("%d, ", nums[i]);
	}
    
    int8_t rssiA = -70;
    uint8_t rssiB = 0xBA;

    int8_t rssiC;
    int8_t rssiD;

    rssiC = rssiA + 3;
    rssiD = rssiB + 3;

    printf("rssiC = %d\n", rssiC);
    printf("rssiD = %d\n", rssiD);

    int result = add(3, 4);
    //int ret = foo();
    printf("Sum: %d\n", result);

    return 0;
} 


