#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int compare(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int previous = INT_MIN;
    int result = 0x0;

    for (int i = 0x0; i < numsSize; ++i) {
        int candidate = MAX(
            MIN(previous + 0x1, nums[i] + k),
            nums[i] - k
        );

        candidate == previous || ++result;
        previous = candidate;
        // printf(" %d ", nums[i]);
        // printf(" %d,", candidate);
    }

    return result;
}
