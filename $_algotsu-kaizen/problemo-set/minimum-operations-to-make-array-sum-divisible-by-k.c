int minOperations(int* nums, int numsSize, int k) {
    int sigma = 0x0;
    for (int i = 0x0; i < numsSize; ++i) sigma += nums[i];
    return sigma % k;
}
