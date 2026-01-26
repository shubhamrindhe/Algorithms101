/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minBitwiseArray(int* nums, int numsSize, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0x0; i < numsSize; ++i) {
        int candidate = -0x1;
        for (int j = 0x0; j < nums[i]; ++j) {
            if ((j | (j + 0x1)) == nums[i]) {
                candidate = j;
                break;
            }
        }

        result[i] = candidate;
    }

    return result;
}
