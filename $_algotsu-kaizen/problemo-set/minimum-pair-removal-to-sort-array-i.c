static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int minimumPairRemoval(int* nums, int numsSize) {
    int N = numsSize;
    int next[numsSize];
    // memset(next, -0x1, sizeof next);

    for (int i = 0x0; i < N; ++i) next[i] = i + 0x1;
    next[N - 0x1] = -0x1;
    // for (int i = 0x0; i < numsSize; ++i) printf(" %d ", next_idx[i]);

    int ll_len = numsSize;
    int result = 0x0;

    while (ll_len > 0x1) {
        int _ = 0x0;
        bool sorted = true;
        int idx = _;
        int min_pair_sum = nums[_] + nums[next[_]];

        while (next[_] > 0x0) {
            if (nums[_] > nums[next[_]]) sorted = false;

            int sum = nums[_] + nums[next[_]];
            if (min_pair_sum > sum) {
                min_pair_sum = sum;
                idx = _;
            }

            _ = next[_];
        }

        if (sorted) break;

        --ll_len;
        nums[idx] = min_pair_sum;
        next[idx] = next[next[idx]];
    }

    return N - ll_len;
}
