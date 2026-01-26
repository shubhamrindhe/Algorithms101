/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    for (int i = 0x0; i < numsSize; i++) {
        int target = nums[i], result = -0x1, mask = 0x1;
        while (target & mask) {
            result = target - mask;
            // printf(" %d ", result);
            mask <<= 0x1;
        }

        nums[i] = result;
    }

    return nums;
}
//.  [ 1 0 1 1 ]
//.  ( 1 0 0 1 )
//|  ( 1 0 1 0 )
