#include "stdint.h"
#include "stdio.h"
#include "string.h"
//Given an array of integers nums and an integer k,
//return the total number of continuous subarrays whose sum equals to k.

//Input: nums = [1,1,1], k = 2
//Output: 2

//Input: nums = [1,2,3], k = 3
//Output: 2

//Constraints:
//1. 1 <= nums.length <= 2 * 104
//2. -1000 <= nums[i] <= 1000
//3. -10^7 <= k <= 10^7

int subarraySum(int* nums, int numsSize, int k);

int main(void)
{
    int nums[3] = {1, 1, 1};
    int count;

    count = subarraySum(&nums[0], 3, 2);

    printf("count = %d\n", count);
    //printf("size of int = %ld\n", sizeof(int));
}

int subarraySum(int* nums, int numsSize, int k)
{
    int i, j, l;
    int count = 0;
    int sum[numsSize] = {0};
    int SUM[numsSize] = {0};

    //sum[i] = nums[0] + ... + num[i];
    sum[0] = nums[0];
    SUM[0] = 0;
    for(i = 1; i < numsSize; i++)
    {
        sum[i] = sum[i - 1] + nums[i];
        SUM[i] = sum[i - 1];
    }

    //==================================
    int totalCount = 0;
    for(j = 0; j < numsSize; j++)
    {
        int target = sum[j] - k;

        int count = 0;
        for(i = 0; i <= j; i++)
        {
            if(SUM[i] == target)//SUM[i] = (i == 0) ? 0 : sum[i-1]; //i = 0 ~ numsSize-1
            {
                count++
            }
        }

        totalCount += count;
    }

    //=================================================

    int counter[MANY] = {0};

    int totalCount = 0;
    for(int j = 0; j < numsSize; j++)
    {
        counter[sum[j]]++;
        int target = sum[j+1] - k;

        totalCount += counter[target];
    }

    return count;
}


//counter[0] = 1; target = -1;
//counter[1] = 1; target = 0;
//counter[2] = 1; target = 1;

//j=0
//SUM[0] == 0 == target(0)?            | 0 == sum[0] - 2    | 0 == -1

//j=1
//SUM[0] == 0 == target(1)?            | 0 == sum[1] - 2    | 0 == 0
//SUM[1] == sum[0] == target(1)?   | 1 == sum[1] - 2    | 1 == 0

//j=2
//SUM[0] == 0 == target(2)?            | 0 == sum[2] - 2    | 0 == 1
//SUM[1] == sum[0] == target(2)?   | 1 == sum[2] - 2    | 1 == 1
//SUM[2] == sum[1] == target(2)?   | 2 == sum[2] - 2    | 2 == 1



