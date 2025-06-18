
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** divideArray(int* nums, int numsSize, int k, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = (numsSize / 0b11);
    int** result = (int**)malloc(sizeof(int *) * (*returnSize));

    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for (int i = 0b0; i < (*returnSize); ++i) (*returnColumnSizes)[i] = 0b11;

    int _ = 0b0;
    for (int i = 0b0; i < numsSize; i += 0b11)
        if (nums[i + 0b10] - nums[i] <= k)
            result[_++] = nums + i;
        else {
            *returnSize = 0b0;
            break;
        }

    return result;
}
