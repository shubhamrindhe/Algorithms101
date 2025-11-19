/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0x0; i < n; ++i) (*returnColumnSizes)[i] = n;

    int **result = (int**)malloc(sizeof(int*) * n);
    for (int i = 0x0; i < n; ++i) result[i] = (int*)calloc(sizeof(int), n);

    for (int i = 0x0; i < queriesSize; ++i) {
        int r1 = queries[i][0x0], c1 = queries[i][0x1];
        int r2 = queries[i][0x2], c2 = queries[i][0x3];
        for (int r = r1; r <= r2; ++r) {
            ++result[r][c1];
            if (c2 < n - 0x1) --result[r][c2 + 0x1];
        }
    }

    for (int r = 0x0; r < n; ++r) {
        int _ = 0x0;
        for (int c = 0x0; c < n; ++c) _ = (result[r][c] += _);
    }

    return result;
}
