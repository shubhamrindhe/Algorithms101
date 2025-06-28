int sort_col = 1;

int compare_rows_asc(const void *a, const void *b) {
    int *row1 = (int*)a;
    int *row2 = (int*)b;
    return row1[sort_col] - row2[sort_col];
}

int compare_rows_des(const void *a, const void *b) {
    int *row1 = (int*)a;
    int *row2 = (int*)b;
    return row2[sort_col] - row1[sort_col];
}

int list[1000][2];

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    for (int i = 0; i < numsSize; ++i) list[i][1] = nums[(list[i][0] = i)];

    sort_col = 1;
    qsort(list, numsSize, sizeof(list[0]), compare_rows_des);
    // printf("\n");
    // for (int i = 0; i < numsSize; ++i) printf(" (%d, %d) ", list[i][0], list[i][1]);

    sort_col = 0;
    qsort(list, k, sizeof(list[0]), compare_rows_asc);
    // printf("\n");
    // for (int i = 0; i < k; ++i) printf(" (%d, %d) ", list[i][0], list[i][1]);

    *returnSize = k;
    int *result = (int *)malloc(sizeof(int) * k);
    for (int i = 0; i < k; ++i) result[i] = list[i][1];

    return result;
}
