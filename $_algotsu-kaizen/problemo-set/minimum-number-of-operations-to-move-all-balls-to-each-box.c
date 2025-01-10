/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize) {
    char _ = '\0';
    int len = 0;
    while((_ = boxes[len]) && ++len);

    int* result = (int*)malloc(len * sizeof(int));
    *returnSize = len;

    for (int i = 0; i < len; ++i) {
        int ops = 0;
        for (int j = 0; j < len; ++j)
            if (i != j && boxes[j] == '1') ops += abs(i - j);
        result[i] = ops;
    }

    return result;
}
