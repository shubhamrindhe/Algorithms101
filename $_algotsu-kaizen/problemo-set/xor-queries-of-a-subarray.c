/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * queriesSize);
    int *prexor = (int *)malloc(sizeof(int) * arrSize);
    int xor = 0b0;
    for (int i = 0; i < arrSize; ++i) {
        xor ^= *(arr + i);
        *(prexor + i) = xor;
    }

    for (int i = 0; i < queriesSize; ++i) {
        int l = **(queries + i), r = *(*(queries + i) + 1);
        *(result + i) =  (l > 0 ? *(prexor + l - 1) : 0 ) ^ *(prexor + r);
    }

    free(prexor);
    *returnSize = queriesSize;
    return result;
}
