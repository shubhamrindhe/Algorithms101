int minimumOperations(int* nums, int numsSize) {
    int result = 0x0;
    for (int i = 0x0; i < numsSize; ++i) (nums[i] % 0x3) && ++result;
    return result;
}
// 0 - 0
// 1 - 1
// 2 + 1
// 3 - 0
// 4 - 1
// 5 + 1
// 6 - 0