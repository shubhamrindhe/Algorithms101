static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int minPairSum(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), compare);
    int result = 0x0;
    int l = 0x0, r = numsSize - 0x1;
    while (l < r) result = maximus(nums[l++] + nums[r--], result);
    return result;
}
