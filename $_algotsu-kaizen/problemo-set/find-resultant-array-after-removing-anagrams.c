/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** removeAnagrams(char** words, int wordsSize, int* returnSize) {
    // unsigned short lens[wordsSize];
    char f[wordsSize][26];
    memset(f, 0x0, sizeof(f));

    // unsigned short links[wordsSize];
    // for (int i = 0x0; i < wordsSize; ++i) links[i] = i - 0x1;

    for (int i = 0x0; i < wordsSize; ++i) {
        char _, *word = words[i];
        unsigned short len = 0x0;
        while ((_ = word[len]) && ++len) ++f[i][_ - 'a'];
        // lens[i] = len;
    }

    char **result = (char**)malloc(sizeof(char*) * wordsSize);
    result[0x0] = words[0x0];
    *returnSize = 0x1;
    int last = 0x0;

    for (int i = 0x1; i < wordsSize; ++i) {
        if (memcmp(f[i], f[last], sizeof(f[i])) == 0x0) continue;
        result[(*returnSize)++] = words[i];
        last = i;
    }

    return result;
}
