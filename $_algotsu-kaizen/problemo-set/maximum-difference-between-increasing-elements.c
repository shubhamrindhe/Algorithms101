#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maximumDifference(int* nums, int numsSize) {
    int result = -1;
    int r = numsSize - 1;
    int l = r - 1;
    while (l >= 0) {
        if (nums[l] < nums[r]) result = MAX(result, nums[r] - nums[l]);
        else if (nums[l] > nums[r]) r = l;
        --l;
    }

    return result;
}
