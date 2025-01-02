/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isVowel(char _) {
    return _ == 'a'
    || _ == 'e'
    || _ == 'i'
    || _ == 'o'
    || _ == 'u';
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;

    int* presum = (int *)malloc(sizeof(int) * wordsSize);
    int count = 0;
    for (int i = 0; i < wordsSize; ++i) {
        char _ = '\0';
        char* word = words[i];
        int len = 0;
        while (_= word[len] && ++len);
        isVowel(*word) && isVowel(word[len - 1]) && ++count;
        presum[i] = count;
    }

    // for (int i = 0; i < wordsSize; ++i) printf(" %d ", presum[i]);

    for (int i = 0; i < queriesSize; ++i) {
        int l = queries[i][0], r = queries[i][1];
        result[i] = presum[r] - (l > 0 ? presum[l - 1] : 0);
    }

    free(presum);

    return result;
}
