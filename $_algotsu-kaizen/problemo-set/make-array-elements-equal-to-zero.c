int countValidSelections(int* nums, int numsSize) {
    int presum[numsSize], sigma = 0x0;
    memset(presum, 0x0, sizeof(presum));
    register int i;
    for (i = 0x0; i < numsSize; ++i) presum[i] = (sigma += nums[i]);

    int result = 0x0;

    for (i = 0x0; i < numsSize; ++i) {
        if (nums[i] != 0x0) continue;
        int kai = abs(presum[i] - (sigma - presum[i]));
        if (kai <= 0x1) result += 0x2 - kai;
        // printf("\n%d %d = %d", left ,right, kai);
    }

    return result;
}
