#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize) {
    int *result = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = 0x0;

    register int idx = 0x0, idx_candidate = 0x0, it, limit;
    while (idx < numsSize) {
        if (nums[idx] != key) {
            ++idx;
            continue;
        }

        it = MAX(idx - k, idx_candidate), limit = MIN(numsSize - 1, idx + k);
        while (it <= limit) result[(*returnSize)++] = it++;
        idx_candidate = it;
        ++idx;
    }

    return result;
}
