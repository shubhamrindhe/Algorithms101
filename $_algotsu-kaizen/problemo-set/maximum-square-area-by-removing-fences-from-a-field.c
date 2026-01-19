const int MOD = 1000000007;

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

bool get_flag(uint8_t *buffer, int idx, int bound) {
    if (idx > bound) return false;
    int byte_idx = idx / 0x8;
    int bit_idx = idx % 0x8;
    return buffer[byte_idx] & (0x1 << bit_idx);
}

void set_flag_bound(uint8_t *buffer, int idx, int bound) {
    if (idx > bound) return;
    int byte_idx = idx / 0x8;
    int bit_idx = idx % 0x8;
    buffer[byte_idx] |= 0x1 << bit_idx;
}

int maximizeSquareArea(int m, int n, int* hFences, int hFencesSize, int* vFences, int vFencesSize) {
    if (m == n) return (m - 0x1) * (n - 0x1);

    qsort(hFences, hFencesSize, sizeof(int), cmp);
    qsort(vFences, vFencesSize, sizeof(int), cmp);


    int S = minimus(m, n);
    int set_size = (S + 0x8) / 0x8;
    uint8_t *flag_buff = (uint8_t*)calloc(sizeof(uint8_t), set_size + 0x1);

    int ij;

    // flagset[m - 1] = true;
    set_flag_bound(flag_buff, m - 1, S);

    for (int i = 0x0; i < hFencesSize; ++i) {
        for (int j = i + 0x1; j < hFencesSize; ++j)
            // flagset[hFences[j] - hFences[i]] = true;
            set_flag_bound(flag_buff, hFences[j] - hFences[i], S);
        // flagset[hFences[i] - 0x1] = true;
        set_flag_bound(flag_buff, hFences[i] - 0x1, S);
        // flagset[m - hFences[i]] = true;
        set_flag_bound(flag_buff, m - hFences[i], S);
    }

    int max_common = -0x1;

    // if (flagset[n - 1])
    //     max_common = maximus(max_common, n - 1);
    if (get_flag(flag_buff, n - 1, S))
        max_common = maximus(max_common, n - 1);

    for (int i = 0x0; i < vFencesSize; ++i) {
        for (int j = i + 0x1; j < vFencesSize; ++j)
            // if (flagset[(ij = vFences[j] - vFences[i])])
            if (get_flag(flag_buff, (ij = vFences[j] - vFences[i]), S))
                max_common = maximus(max_common, ij);

        int i1 = vFences[i] - 0x1;
        int in = n - vFences[i];
        // if (flagset[i1]) max_common = maximus(max_common, i1);
        if (get_flag(flag_buff, i1, S)) max_common = maximus(max_common, i1);
        // if (flagset[in]) max_common = maximus(max_common, in);
        if (get_flag(flag_buff, in, S)) max_common = maximus(max_common, in);
    }

    free(flag_buff);
    int result = -0x1;

    if (max_common > 0x0) {
        int size = max_common;
        result = (0x1LL * size * size) % MOD;
    }

    return result;
}
