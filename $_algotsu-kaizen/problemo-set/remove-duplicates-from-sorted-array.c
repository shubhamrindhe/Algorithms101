int removeDuplicates(int* nums, int numsSize) {
    int _ = 0;
    int prev = nums[_++];

    for (int i = 1; i < numsSize; ++i)
        if (prev != nums[i]) {
            nums[_++] = nums[i];
            prev = nums[i];
        }

    return _;
}
