int firstMissingPositive(int* nums, int numsSize) {
    int size = numsSize + 2;
    bool *flags = (bool *)calloc(sizeof(bool ), size);

    for (int i = 0; i < numsSize; ++i)
        if (nums[i] > 0 && nums[i] < size) flags[nums[i]] = true;

    int result = 0;

    for (int i = 1; i < size; ++i)
        if (!flags[i]) {
            result = i;
            break;
        }

    free(flags);

    return result;
}