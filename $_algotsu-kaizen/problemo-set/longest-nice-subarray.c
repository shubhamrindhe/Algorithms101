int longestNiceSubarray(int* nums, int numsSize) {
    int maximus = 1;

    // for (int l = 0; l < numsSize; ++l) {
    //     int local_maximus = 1, bits = nums[l];
    //     for (int r = l + 1; r < numsSize; ++r)
    //         if ((bits & nums[r]) == 0) {
    //             bits |= nums[r];
    //             ++local_maximus;
    //         } else break;
    //     if (maximus < local_maximus) maximus = local_maximus;
    // }

    int l = 0, bits = 0;
    for (int r = 0; r < numsSize; ++r) {
        while ((bits & nums[r])) bits ^= nums[l++];
        bits |= nums[r];
        int currentLength = (r - l + 1);
        if (maximus < currentLength) maximus = currentLength;
    }

    return maximus;
}