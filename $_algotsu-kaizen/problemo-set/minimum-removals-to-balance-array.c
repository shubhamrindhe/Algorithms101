int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

int minRemoval(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int window = 0x0;
    int r = 0x0;

    for (int l = 0x0; (l + window) < numsSize; ++l) {
        long long limit = 1LL * nums[l] * k;
        while ((r < numsSize) && nums[r] <= limit) ++r;
        // printf("\n %d %d %d", l, r, window);
        window = maximus(window, r - l);
    }

    return numsSize - window;
}
