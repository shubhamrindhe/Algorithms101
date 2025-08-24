int longestSubarray(int* nums, int numsSize) {
    int result = 0x0, f[0x2] = { 0x0 };
    bool _ = false;
    // int xor = 1;

    for (int i = 0; i < numsSize; ++i)
        if (nums[i])
            ++f[_];
        else {
            if (result < f[0x0] + f[0x1])
                result = f[0x0] + f[0x1];
            f[(_ = !_)] = 0x0;
        }

    if (result < f[0x0] + f[0x1])
        result = f[0x0] + f[0x1];

    return result == numsSize ? result - 1 : result;
}
