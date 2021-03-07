/* 
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. 
*/

#include <stdio.h>
#include <stdlib.h>

int* twosum(int* nums, int numsSize, int target, int* returnSize)
{
    int* result = malloc(2*sizeof(int));
    
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i; i < numsSize; j++)
        {
            if (nums[i] - target == nums[j])
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main()
{
    int tar = 9;
    int tSize = 4;
    int* arr = malloc(tSize * sizeof(int));
    arr[0] = 2;
    arr[1] = 7;
    arr[2] = 11;
    arr[3] = 15;
    int* rSize = 0;
    int* ans = twosum(arr, tSize, tar, rSize);
    printf("%d", *ans);
    printf("[%d, %d]", ans[0], ans[1]);
    return 0;
}