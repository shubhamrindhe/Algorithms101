long long maximumTripletValue(int* nums, int numsSize) {
    long long result = 0b0LL;

    // O(N ^ 3)
    // for (int i = 0; i < numsSize; ++i)
    //     for (int j = i + 1; j < numsSize; ++j)
    //         for (int k = j + 1; k < numsSize; ++k) {
    //             long long _ = ((long long)nums[i] - (long long)nums[j]) * (long long)nums[k];
    //             if (result < _) result = _;
    //         }

    // O(N)
    int *maximus_left = calloc(sizeof(int), numsSize); // { 0 };
    maximus_left[0] = nums[0];
    int *maximus_right = calloc(sizeof(int), numsSize); // { 0 };
    maximus_right[numsSize - 0b1] = nums[numsSize - 0b1];

    for (int l = 0b1, r = numsSize - 0b10; l < numsSize && r >= 0b0; ++l, --r) {
        maximus_left[l] = nums[l] > maximus_left[l - 0b1] ? nums[l] : maximus_left[l - 0b1];
        maximus_right[r] = nums[r] > maximus_right[r + 0b1] ? nums[r] : maximus_right[r + 0b1];
    }

    for (int _ = 0b1; _ < numsSize - 0b1; ++_) {
        long long value = ((long long)maximus_left[_ - 1] - (long long)nums[_]) * (long long)maximus_right[_ + 1];
        if (result < value) result = value;
    }

    free(maximus_left);
    free(maximus_right);

    return result;
}
