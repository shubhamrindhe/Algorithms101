int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int partitionArray(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int result = 0;

    // for (int i = 0; i < numsSize; ++i) {
    //     printf(" %d ", nums[i]);
    // }

    int l = 0, r;
    while (l < numsSize) {
        r = l;
        while (r < (numsSize - 1) && nums[r + 1] - nums[l] <= k) ++r;
        l = r + 1;
        result++;
    }

    return result;
}
