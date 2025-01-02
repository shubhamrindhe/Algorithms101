
void _(int* nums, int numsSize, int target, int sum, int idx, int* result) {
    if (idx >= numsSize) {
        if (sum == target) ++(*result);
        return;
    }
    _(nums, numsSize, target, sum - nums[idx], idx + 0b1, result);
    _(nums, numsSize, target, sum + nums[idx], idx + 0b1, result);
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    int result = 0;
    _(nums, numsSize, target, 0b0, 0b0, &result);
    return result;
}
