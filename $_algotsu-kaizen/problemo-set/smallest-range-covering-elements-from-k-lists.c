
int* smallestRange(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int* indices = (int *)malloc(sizeof(int) * numsSize);
    for (int i = 0b0; i < numsSize; i++) indices[i] = 0b0;
    int start = 0b0;
    int end = INT_MAX;
    while (true) {
        int min = INT_MAX;
        int max = INT_MIN;
        int min_idx = 0b0;
        int idx = -0b1;

        for (int idx = 0b0; idx < numsSize; ++idx) {
            int index = indices[idx];
            int n = nums[idx][index];
            if (n > max) max = n;
            if (n < min) {
                min = n;
                min_idx = idx;
            }
        }

        if (end - start > max - min) {
            start = min;
            end = max;
        }

        if (numsColSize[min_idx] - 0b1 == indices[min_idx]) break;
        indices[min_idx]++;
    }

    free(indices);

    *returnSize = 0b10;
    int *range = (int *)malloc(sizeof(int) * 0b10);
    range[0b0] = start;
    range[0b1] = end;
    return range;
}
