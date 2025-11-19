/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int f[numsSize];
    memset(f, 0x0, sizeof(f));

    int *result = (int *)malloc(sizeof(int) * 2);
    *returnSize = 0x0;

    for (int i = 0x0; i < numsSize; ++i) ++f[nums[i]];
    for (int i = 0x0; i < numsSize; ++i)
        if (f[i] == 0x2) {
            result[(*returnSize)++] = i;
            if (*returnSize == 0x2) break;
        }

    return result;
}
