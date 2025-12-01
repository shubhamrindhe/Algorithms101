/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    unsigned int x = 0x0;
    // unsigned int _ = 0x1 << 0b011111; // 0x20

    bool *result = (bool*)malloc(sizeof(bool) * numsSize);
    *returnSize = numsSize;

    for (int i = 0x0; i < numsSize; ++i) {
        // x = x * 0x2 + nums[i];
        x <<= 0x1;
        x += nums[i];
        result[i] = (x %= 0x5) == 0x0;
    }

    return result;
}
