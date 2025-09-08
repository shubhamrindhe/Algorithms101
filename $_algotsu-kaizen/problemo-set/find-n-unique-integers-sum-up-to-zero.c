
int* sumZero(int n, int* returnSize) {
    *returnSize = n;
    int *result = (int *)calloc(sizeof(int), n);
    int m = n / 0x2;
    for (int i = 0x0, x = i + 1; i < m; ++i, ++x)
        result[i] = -x, result[n - 0x1 - i] = x;
    return result;
}
