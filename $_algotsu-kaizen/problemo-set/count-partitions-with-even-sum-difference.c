int countPartitions(int* nums, int numsSize) {
    int sigma = 0x0;

    int result = 0x0;
    for (int i = 0x0; i < numsSize; ++i) sigma += nums[i];

    int _ = 0x0;
    for (int i = 0x0; i < numsSize - 0x1; ++i)
        (((_ += nums[i]) << 0x1) - sigma) & 0x1 || ++result;
        // _ += nums[i];
        // ((_ - sigma + _) & 0x01) || ++result;

    return result;
}
