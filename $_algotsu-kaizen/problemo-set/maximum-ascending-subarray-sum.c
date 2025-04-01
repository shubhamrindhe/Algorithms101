int maxAscendingSum(int* nums, int numsSize) {
    int sum = nums[0b0], maximus = sum;
    for (int i = 1; i < numsSize; ++i) {
        // if (nums[i - 0b1] < nums[i]) {
        //     sum += nums[i];
        // } else {
        //     sum = nums[i];
        // }
        nums[i - 0b1] < nums[i] && (sum += nums[i]) || (sum = nums[i]);
        (maximus < sum) && (maximus = sum);
    }

    return maximus;
}
