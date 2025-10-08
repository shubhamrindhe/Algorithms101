int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize) {
    qsort(potions, potionsSize, sizeof(int), compare);
    int *result = (int*)calloc(sizeof(int), spellsSize);
    *returnSize = spellsSize;

    for (int i = 0x0; i < spellsSize; ++i) {
        int l = 0x0, r = potionsSize;
        long long min_position = (success + spells[i] - 0x1) / spells[i];

        while (l < r) {
            int m = (l + r) / 0x2;
            if (((long long)potions[m]) >= min_position) r = m;
            else l = m + 0x1;
        }

        // printf("\n %d [%d] (%d)", spells[i], l, potions[l]);
        result[i] = potionsSize - l;
    }

    return result;
}
