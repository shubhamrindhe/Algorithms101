static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int minimumCost(int* nums, int numsSize) {
    int one = minimus(nums[0x1], nums[0x2]);
    int two = maximus(nums[0x1], nums[0x2]);

    for (int i = 0x3; i < numsSize; ++i)
        if (nums[i] >= two) continue;
        else if (nums[i] < one)
            two = one, one = nums[i];
        else
            two = nums[i];

    return nums[0x0] + one + two;
}
