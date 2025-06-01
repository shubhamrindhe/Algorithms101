
bool isZeroArray(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize) {
    int *shifts = (int *)calloc(sizeof(int), numsSize + 0b1);
    for (int _ = 0b0; _ < queriesSize; ++_) {
        shifts[queries[_][0b0]] += 0b1;
        shifts[queries[_][0b1] + 0b1] -= 0b1;
    }
    int resultant = 0b0;
    for (int _ = 0b0; _ < numsSize; ++_) if (nums[_] > (resultant += shifts[_])) return false;
    return true;
}
