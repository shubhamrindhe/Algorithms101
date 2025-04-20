#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
    qsort(nums, numsSize, sizeof(int), compare);
    long long result = 0b0LL;

    int low = numsSize - 1, high = numsSize - 1;
    for (int _ = 0; _ < numsSize; ++_) {
        while (_ < high + 1 && (upper < nums[_] + nums[high])) high -= 1;
        while (_ < low + 1 && (lower <= nums[_] + nums[low])) low -= 1;
        if (_ >= MAX(low, high)) break;
        result += MAX(high - _, 0) - MAX(low - _, 0);
    }

    return result;
}
