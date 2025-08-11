#define MOD 1000000007

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int p[0x1F] = { 0x0 }, plen = 0x0;

    int guinea_pig = n, power = 0b1;
    while (power <= guinea_pig) {
        if (power & guinea_pig)
            p[plen++] = power;
        power <<= 0b1;
    }

    // for (int i = 0; i < sizeof(p) / sizeof(p[0]); ++i)
    //     printf(" %d ", p[i]);
    int *result = (int *)malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;

    // long long prefix_product[plen];
    // memset(prefix_product, 0, sizeof(prefix_product));
    // prefix_product[0] = p[0];
    // for (int i = 1; i < plen; ++i)
    //     prefix_product[i] = (prefix_product[i - 1] * p[i]) % MOD;
    //     // printf(" %d ", prefix_product[i]);

    for (int i = 0; i < queriesSize; ++i) {
        int start = queries[i][0];
        int end = queries[i][1];
        long long val = 1;
        for (int j = start; j <= end; ++j)
            val = (val * p[j]) % MOD;
        result[i] = (int)val;
        // result[i] = (int)prefix_product[end];
        // if (start > 0) result[i] /= (int)prefix_product[start - 1];
    }

    return result;
}
