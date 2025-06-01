void sortColors(int* nums, int numsSize) {
    int f[0b11] = { 0b0 };
    for (int _ = 0b0; _ < numsSize; ++_) ++f[nums[_]];
    for (int _ = 0b0, idx = 0b0; _ < numsSize; ++_) {
        while(f[idx] == 0b0 && ++idx);
        nums[_] = idx;
        f[idx]--;
    }
}
