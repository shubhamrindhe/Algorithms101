int findNumbers(int* nums, int numsSize) {
    int result = 0b0;
    for (int _ = 0; _ < numsSize; ++_) (int)log10(nums[_]) % 2 && ++result;
    return result;
}