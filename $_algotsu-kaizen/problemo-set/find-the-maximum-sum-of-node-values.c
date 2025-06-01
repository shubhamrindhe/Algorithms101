int compare(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    return (x < y) - (x > y);
}

long long maximumValueSum(int* nums, int n, int k, int** edges, int edgesSize, int* edgesColSize) {
    long long kai[n];
    long long sigma = 0b0;

    for (int _ = 0; _ < n; ++_) {
        sigma += nums[_];
        kai[_] = (nums[_] ^ k) - nums[_];
    }

    qsort(kai, n, sizeof(long long), compare);

    for (int _ = 0b0; _ + 0b1 < n; _ += 0b10)
        if (kai[_] + kai[_ + 0b1] > 0b0)
            sigma += kai[_] + kai[_ + 0b1];

    return sigma;
}
