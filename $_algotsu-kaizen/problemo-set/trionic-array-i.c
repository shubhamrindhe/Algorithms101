bool isTrionic(int* nums, int numsSize) {
    if (
        numsSize <= 0x3 ||
        nums[0x0] >= nums[0x1] ||
        nums[numsSize - 0x2] >= nums[numsSize - 0x1]
    ) return false;

    unsigned short shifts = 0x0;
    bool is_strictly_increasing_mode = true;

    for (int i = 0x1; i < numsSize; ++i)
        if (nums[i] == nums[i - 0x1]) return false;
        else if ((nums[i] > nums[i - 0x1]) != is_strictly_increasing_mode) {
            is_strictly_increasing_mode = !is_strictly_increasing_mode;
            if (++shifts > 0x2) return false;
        }

    // printf("%d", shifts);
    return shifts == 0x2;
}

// [9,|4,|6,8]
// [1,3,5,4,2,6]
// [2,1,3]
// [2,4,3,3]
// [1,6,6,3,7]
// [6,7,5,1]
// [1,2,3]
// [1,2,1]
