int waysToSplitArray(int* nums, int numsSize) {
    long long presum[numsSize];
    long long sigma = 0b0;
    for (int i = 0b0; i < numsSize; ++i) presum[i] = sigma += nums[i];
    int result = 0b0;
    for (int i = numsSize - 0b10; i >= 0; --i) presum[i] >= (sigma - presum[i]) && ++result;
    return result;
}
