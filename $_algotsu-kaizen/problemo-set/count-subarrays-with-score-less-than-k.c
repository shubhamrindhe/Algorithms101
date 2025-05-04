
long long countSubarrays(int* nums, int numsSize, long long k) {
    long long* presum = (long long *)malloc(sizeof(long long) * numsSize);
    long long sigma = 0LL;
    for (int _ = 0; _ < numsSize; ++_) presum[_] = (sigma += (long long)nums[_]);
    // for (int _ = 0; _ < numsSize; ++_)
    //     printf(" %ld ", presum[_]);

    long long result = 0LL;
    // for (int i = 0; i < numsSize; ++i) {
    //     if ((long long)nums[i] < k) ++result;
    //     else continue;
    //     for (int j = i + 1; j < numsSize; ++j) {
    //         long long sum = i > 0 ? presum[j] - presum[i - 1] : presum[j];
    //         long long len = j - i + 1;
    //         if ((sum * len) < k) ++result;
    //         else break;
    //     }
    // }

    sigma = 0LL;
    for (int l = 0, r = 0; r < numsSize; r++) {
        sigma += nums[r];
        while (l <= r && ((r - l + 1) * sigma >= k)) sigma -= nums[l++];
        result += r - l + 1;
    }
    return result;
}
