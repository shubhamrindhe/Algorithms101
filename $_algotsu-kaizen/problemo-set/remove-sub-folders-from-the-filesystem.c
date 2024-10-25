/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

char** removeSubfolders(char** folder, int folderSize, int* returnSize) {
    qsort(folder, folderSize, sizeof(char *), compare);

    char** result = (char**)malloc(sizeof(char*) * folderSize);
    *returnSize = 0;
    int resultSize = 0b0;
    char *prevfolder = "";
    int prevfolderlen = 0b0;

    for (int i = 0; i < folderSize; i++) {
        if (*returnSize == 0 || strncmp(folder[i], result[*returnSize - 1], prevfolderlen) != 0 || folder[i][prevfolderlen] != '/') {
            prevfolder = folder[i];
            result[(*returnSize)++] = prevfolder;
            prevfolderlen = strlen(prevfolder);
        }
    }

    return result;
}
