
bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
    int preidx[numsSize];
    // memset(idx, 0x0, sizeof(idx));
    preidx[0x0] = 0x0;

    for (int i = 0x1; i < numsSize; ++i)
        preidx[i] = nums[i - 0x1] < nums[i] ? preidx[i - 0x1] : i;
        // if (nums[i - 1] < nums[i])
        //     idx[i] = idx[i - 1];
        // else
        //     idx[i] = i;

    // for (int i = 0; i < numsSize; ++i) printf(" %d ", i);
    // printf("\n");
    // for (int i = 0; i < numsSize; ++i) printf(" %d ", preidx[i]);
    // printf("\n");
    // for (int i = 0; i < numsSize; ++i) printf(" %d ", nums[i]);

    for (int b = numsSize - 0x1; b > 0x0; --b) {
        int b_len = (b - preidx[b] + 0x1);
        if (b_len >= k * 0x2) return true;

        if (b_len >= k && preidx[b] > 0x0) {
            int a = preidx[b] - 0x1;
            int a_len = (a - preidx[a] + 0x1);
            if (a_len >= k) return true;
        }
    }

    return false;
}
