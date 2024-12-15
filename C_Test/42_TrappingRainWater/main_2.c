#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "stdlib.h"

//Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it can trap after raining.

//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6
//Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

//Input: height = [4,2,0,3,2,5]
//Output: 9

//Constraints:

//n == height.length
//1 <= n <= 2 * 104
//0 <= height[i] <= 105

int trap(int* height, int heightSize){
    int *h = height;
    int N = heightSize;
    int lMax = h[0];
    int rMax = h[N-1];
    int l = 0;
    int r = N-1;
    int sum = 0;

    while(l <= r){
        if((h[r] > h[l])){
            if(lMax > h[l]){
                sum += lMax - h[l];
            }else{
                lMax = h[l];
            }
            l++;
        }else{
            if(rMax > h[r]){
                sum += rMax - h[r];
            }else{
                rMax = h[r];
            }
            r--;
        }
    }

    return sum;
}

int main(void)
{ 
    //int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int height[6] = {4,2,0,3,2,5};
    //printf("area = %d\n", trap(height, 12));
    printf("area = %d\n", trap(height, 6));
    return 0;
}



