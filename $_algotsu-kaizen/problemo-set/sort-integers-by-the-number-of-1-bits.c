int cmp(const void *a, const void *b) {
    int A = *(int*)a;
    int B = *(int*)b;
    int f1_a = __builtin_popcount(A);
    int f1_b = __builtin_popcount(B);
    return f1_a == f1_b ? (A - B) : f1_a - f1_b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortByBits(int* arr, int arrSize, int* returnSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    *returnSize = arrSize;
    return arr;
}
