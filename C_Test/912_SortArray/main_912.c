#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given an array of integers nums, sort the array in ascending order.

//Constraints:
    //1 <= nums.length <= 5 * 104
    //-5 * 104 <= nums[i] <= 5 * 104


void merge(int *ptr, int front, int mid, int end){
	int leftSize = mid - front + 1;
	int rightSize = end - mid;
	int leftSub[leftSize];
	int rightSub[rightSize];
	int idxLeft = 0;
	int idxRight = 0;

	for(int i = 0; i < leftSize; i++){
		leftSub[i] = ptr[front + i];
	}

	for(int i = 0; i < rightSize; i++){
		rightSub[i] = ptr[mid + 1 + i];
	}

	for(int i = front; i <= end; i++){
		//check if leftSub[idxLeft] should be put in ptr first
		if((idxLeft < leftSize) && (idxRight < rightSize)){
			if(leftSub[idxLeft] < rightSub[idxRight]){
				ptr[i] = leftSub[idxLeft];
				idxLeft++;
			}
			else{
				ptr[i] = rightSub[idxRight];
				idxRight++;
			}
		}
		else if((idxLeft >= leftSize) && (idxRight < rightSize)){
			ptr[i] = rightSub[idxRight];
			idxRight++;
		}
		else if((idxLeft < leftSize) && (idxRight >= rightSize)){
			ptr[i] = leftSub[idxLeft];
			idxLeft++;
		}
	}
}

void mergeSort(int *ptr, int front, int end){
	if(front >= end){
		return;
	}

	int mid = (front+end)/2;

	mergeSort(ptr, front, mid);
	mergeSort(ptr, mid+1, end);
	merge(ptr, front, mid, end);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    int *p_nums = malloc(numsSize * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        p_nums[i] = nums[i];
    }

    mergeSort(p_nums, 0, numsSize-1);

    *returnSize = numsSize;
    return p_nums;
}


int main(void)
{
    int nums[9] = {10,9,8,7,6,5,4,3,2};
    int returnSize;

    int *p_nums = sortArray(&nums[0], 9, &returnSize);

    printf("[");
    for(int i = 0; i < 9; i++){
        printf("%d,", p_nums[i]);
    }
    printf("]\n");

    free(p_nums);

    return 0;
}



