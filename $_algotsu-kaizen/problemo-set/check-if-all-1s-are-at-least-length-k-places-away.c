
bool kLengthApart(int* nums, int numsSize, int k) {
    int idx = 0x0, last = -0x1;

    while (idx < numsSize) {
        // printf("\n%d - %d", idx, last);
        if (nums[idx] == 1) {
            if (last >= 0x0 && (idx - last) <= k) return false;
            last = idx;
        }

        ++idx;
    }

    return true;
}
