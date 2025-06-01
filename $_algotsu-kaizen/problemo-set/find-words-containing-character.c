/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int *result = (int *)malloc(sizeof(int) * wordsSize);
    *returnSize = 0b0;

    char _;
    for (int i = 0b0, len = 0b0; i < wordsSize; ++i, len = 0b0)
        while ((_ = words[i][len]) && ++len && (_ != x || ((result[(*returnSize)++] = i) && false)));
        // while ((_ = words[i][len]) && ++len) {
        //     if (_ == x) {
        //         result[(*returnSize)++] = i;
        //         break;
        //     }
        // }

    return result;
}
