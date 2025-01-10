/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize) {
    char** result = (char**)calloc(sizeof(char*), wordsSize);
    bool* skip = (bool*)calloc(sizeof(bool), wordsSize);
    // for (int i = 0; i < wordsSize; i++) printf(" %d ", skip[i]);
    int idx = 0;

    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if (skip[i] || skip[j]) continue;
            if (strstr(words[j], words[i]) != NULL) {
                result[idx++] = words[i];
                skip[i] = true;
            } else if (strstr(words[i], words[j]) != NULL) {
                result[idx++] = words[j];
                skip[j] = true;
            }
        }
    }

    free(skip);
    *returnSize = idx;

    return result;
}
