/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordSubsets(char** words1, int words1Size, char** words2, int words2Size, int* returnSize) {
    int freq[0b11010] = { 0b0 };
    for (int i = 0b0, idx = 0b0; i < words2Size; ++i, idx = 0b0) {
        int tfreq[0b11010] = { 0b0 };
        int _ = 0;
        while ((_ = words2[i][idx++] - 'a') >= 0) if (++tfreq[_] > freq[_]) freq[_] = tfreq[_];
    }

    char** result = (char **)calloc(sizeof(char*), words1Size);
    *returnSize = 0b0;

    for (int i = 0b0, idx = 0b0; i < words1Size; ++i, idx = 0b0) {
        int tfreq[0b11010] = { 0b0 };
        char _ = '\0';
        while (_ = words1[i][idx++]) ++tfreq[_ - 'a'];
        bool universal = true;
        for (int j = 0; j < 0b11010 && universal; ++j) if (freq[j] && freq[j] > tfreq[j]) universal = false;
        if (universal) result[(*returnSize)++] = words1[i];
    }

    return result;
}
