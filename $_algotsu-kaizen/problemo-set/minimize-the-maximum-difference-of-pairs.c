int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int minimizeMax(int* nums, int numsSize, int p) {
    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0, right = abs(nums[numsSize - 1] - nums[0]);
    while (left < right) {
        int m = left + (right - left) / 2, pairs = 0;
        for (int i = 1; i < numsSize; ++i)
            if (abs(nums[i] - nums[i - 1]) <= m)
                ++pairs, ++i;
        if (pairs >= p)
            right = m;
        else
            left = m + 1;
    }
    return left;
}
