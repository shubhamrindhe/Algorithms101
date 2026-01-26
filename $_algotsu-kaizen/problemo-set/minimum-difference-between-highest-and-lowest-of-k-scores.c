int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int minimumDifference(int* nums, int numsSize, int k) {
    int l = 0x0, r = k - 0x1, result = INT_MAX;//abs(nums[r] - nums[l]);
    // if (k == numsSize || k == 0x1) return result;
    qsort(nums, numsSize, sizeof(int), cmp);
    while (r < numsSize) result = minimus(result, nums[r++] - nums[l++]);
    return result;
}
