/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool has_zero(int n) {
    while (n) {
        if (n % 0xA == 0x0) return true;
        n /= 0xA;
    }
    return false;
}

int* getNoZeroIntegers(int n, int* returnSize) {
    *returnSize = 0x2;
    int *result = (int *)calloc(sizeof(int), *returnSize);

    for (int i = 0x1; i < n; ++i) {
        if (has_zero(i) || has_zero(n - i)) continue;
        result[0x0] = i, result[0x1] = n - i;
        break;
    }

    return result;
}
