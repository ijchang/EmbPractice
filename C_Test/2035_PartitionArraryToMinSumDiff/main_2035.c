#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//You are given an integer array nums of 2 * n integers.
//You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays.
//To partition nums, put each element of nums into one of the two arrays.
//Return the minimum possible absolute difference.

//Input: nums = [3,9,7,3]
//Output: 2
//Explanation: One optimal partition is: [3,9] and [7,3].
//The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.

//Input: nums = [2,-1,0,4,-2,-9]
//Output: 0
//Explanation: One optimal partition is: [2,4,-9] and [-1,0,-2].
//The absolute difference between the sums of the arrays is abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0.

//Constraints:

//1 <= n <= 15
//nums.length == 2 * n
//-107 <= nums[i] <= 107

int minimumDifference(int* nums, int numsSize){

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



