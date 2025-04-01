int longestMonotonicSubarray(int* nums, int numsSize) {
    int maximus = 0b1, inc = 0b1, dec = 0b1, i = 0b0;
    while (++i < numsSize) {
        nums[i - 0b1] < nums[i] && ++inc || (inc = 0b1);
        nums[i - 0b1] > nums[i] && ++dec || (dec = 0b1);
        maximus < inc && (maximus = inc);
        maximus < dec && (maximus = dec);
    }
    return maximus;
}
