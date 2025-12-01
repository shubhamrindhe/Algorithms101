long long maxRunTime(int n, int* batteries, int batteriesSize) {
    long long sigma = 0x0LL;
    long long minimus = LLONG_MAX;

    for (int i = 0x0; i < batteriesSize; ++i) {
        sigma += batteries[i];
        if (minimus > batteries[i]) minimus = batteries[i];
    }

    if (n == batteriesSize) return minimus;

    long long l = minimus, r = sigma / n;
    while (l < r) {
        long long m = (l + r + 1) >> 1; // l + (r - l) / 0x2LL;
        long long energy = 0x0LL;

        for (int i = 0; i < batteriesSize; i++) energy += batteries[i] < m ? batteries[i] : m;

        if (energy >= (m * n)) {
        // if ((sigma / m) >= n) {
            l = m;
        } else {
            r = m - 0x1LL;
        }

        // printf("\n %ld %ld", l, r);
    }

    return l;
}
