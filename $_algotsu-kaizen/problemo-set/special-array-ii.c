
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    bool* result = (bool *)calloc(queriesSize, sizeof(bool));
    *returnSize = queriesSize;
    int prefix[numsSize];
    prefix[0] = 0;
    int parity = nums[0] % 2, boundaryCount = 0;
    for (int i = 1; i < numsSize; ++i) {
        int newParity = nums[i] % 2;
        if (parity == newParity) ++boundaryCount;
        parity = newParity;
        prefix[i] = boundaryCount;
    }

    for (int i = 0; i < queriesSize; ++i) {
        int* query = queries[i];
        int start = query[0], end = query[1];
        result[i] = prefix[start] == prefix[end];
    }

    return result;
}
