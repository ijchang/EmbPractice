#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"
//Given an integer array nums and an integer k,
//return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k,
//or false otherwise.

//An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

//Input: nums = [23,2,4,6,7], k = 6
//Output: true
//Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

//Input: nums = [23,2,6,4,7], k = 6
//Output: true
//Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
//42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

//Input: nums = [23,2,6,4,7], k = 13
//Output: false

//Constraints
//1. 1 <= nums.length <= 10^5
//2. 0 <= nums[i] <= 10^9
//3. 0 <= sum(nums[i]) <= 2^31 - 1
//4. 1 <= k <= 2^31 - 1

#define CAPACITY 100000

typedef struct hashEntry
{
    int sum;
    int count;
    int init;
}entry_T;

int maxOffset = 0;

//perform hashTbl[sum]++
void addOne(entry_T* p_hashTbl, int sum)
{
    int index, idx;
    int cnt = 0;

    index = (sum % CAPACITY + CAPACITY) % CAPACITY;

    //check init
    if(p_hashTbl[index].init == false)
    {
        p_hashTbl[index].sum = sum;
        p_hashTbl[index].count++;
        p_hashTbl[index].init = true;
    }
    else//this entry has been used before
    {
        //check collision
        if(p_hashTbl[index].sum == sum)
        {
            p_hashTbl[index].count++;
        }
        else//collision! Find the next availabe entry
        {
            idx = index;
            cnt = 0;
            while(1)
            {
                cnt++;
                if(cnt > maxOffset)
                {
                    maxOffset = cnt;
                }

                idx = (idx + 1) % CAPACITY;
                if((p_hashTbl[idx].init == true) && (p_hashTbl[idx].sum == sum))
                {
                    p_hashTbl[idx].count++;
                    break;
                }
                else if(p_hashTbl[idx].init == false)
                {
                    p_hashTbl[idx].sum = sum;
                    p_hashTbl[idx].count++;
                    p_hashTbl[idx].init = true;
                    break;
                }
            }
        }
    }
}

int getCnt(entry_T* p_hashTbl, int target)
{
    int index;
    int i;

    index = (target % CAPACITY + CAPACITY) % CAPACITY;

    if((p_hashTbl[index].init == true) && (p_hashTbl[index].sum == target))
    {
        return p_hashTbl[index].count;
    }
    else//collision! Find the exact entry
    {
        int idx = index;
        if(p_hashTbl[index].init == true)//only checks when p_hashTbl[index].sum != target. This can increase run-tim efficiency a lot
        {
            for(i = 0; i < maxOffset; i++)
            {
                idx = (idx + 1) % CAPACITY;
                if((p_hashTbl[idx].init == true) && (p_hashTbl[idx].sum == target))
                {
                    return p_hashTbl[idx].count;
                }
            }
        }
    }

    return 0;
}

bool checkSubarraySum(int* nums, int numsSize, int k)
{
    int i;
    int cnt = 0;
    int SUM = 0;

    entry_T *p_hashTbl = calloc(CAPACITY, sizeof(entry_T));

    printf("numsSize = %d\n", numsSize);

    if(k == 0)
    {
        return true;
    }

    //=================================
    for(i = 0; i < numsSize; i++)
    {
        addOne(p_hashTbl, (SUM % k));

        SUM += nums[i];
        //how many sum[j] in j = 0 ~ i have the same mod as sum[i+1]
        cnt += getCnt(p_hashTbl, (SUM % k));
        if((cnt > 0) && ((nums[i] % k) == 0))
        {
            cnt--;
        }

        if(cnt > 0)
        {
            break;
        }
    }

    if(cnt > 0)
    {
        return true;
    }

    return false;
}


int main(void)
{
    int nums[10000];
    bool answer;
////    int count;
    FILE *fptr;
////
    if((fptr = fopen("./input2.txt", "r")) != NULL)
    {
        for(int index = 0; index < 10000; index++)
        {
            fscanf(fptr, "%d,", &nums[index]);
        }

        fclose(fptr);
    }
//    int nums[5] = {23,2,6,4,7};
//    bool answer;
    answer = checkSubarraySum(&nums[0], 10000, 6);
//
    printf("answer = %d\n", answer);

    return 0;
}



