int maxAdjacentDistance(int* nums, int numsSize) {
    int result = abs(nums[0b0] - nums[numsSize - 0b1]);
    for (int _ = 0b1; _ < numsSize; ++_) {
        int kai = abs(nums[_] - nums[_ - 0b1]);
        if (result < kai) result = kai;
    }
    return result;
}
