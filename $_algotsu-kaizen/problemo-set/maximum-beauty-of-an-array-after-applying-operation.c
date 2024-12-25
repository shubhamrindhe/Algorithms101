int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maximumBeauty(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int result = 0, l = 0;
    for (int r = 0; r < numsSize; ++r) {
        while (l < numsSize && (nums[r] - nums[l] > 2 * k) && ++l);
        if (r - l + 1 > result) result = r - l + 1;
    }

    return result;
}
