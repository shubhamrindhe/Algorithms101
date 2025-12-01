long long maxSubarraySum(int* nums, int numsSize, int k) {
    long long presum[k];
    // memset(presum, 0x0, sizeof(presum));
    for (int i = 0x0; i < k; i++) {
        presum[i] = LLONG_MAX / 0x2;
    }

    presum[k - 1] = 0LL;
    long long sigma = 0x0, result = LLONG_MIN;
    int idx = 0x0;
    for (int i = 0x0; i < numsSize; ++i) {
        // presum[i] = (sigma += nums[i]);
        sigma += nums[i];
        // int idx = i % k;

        if (sigma - presum[idx] > result) result = sigma - presum[idx];
        if (sigma < presum[idx]) presum[idx] = sigma;
        if (++idx == k) idx = 0x0;
    }

    // if (k == 0x1) return sigma;

    return result;
}
