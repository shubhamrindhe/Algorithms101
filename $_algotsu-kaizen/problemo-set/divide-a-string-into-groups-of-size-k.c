/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** divideString(char* s, int k, char fill, int* returnSize) {
    int len = 0;
    while (s[len] && ++len);

    *returnSize = (len + k - 1) / k;
    char **result = (char **)malloc(sizeof(char*) * *returnSize);

    for (int i = 0; i < *returnSize; ++i) {
        char *group = (char*)malloc(sizeof(char) * (k + 1));
        for (int j = 0, offset = i * k; j < k; ++offset, ++j)
            group[j] = offset < len ? s[offset] : fill;
        group[k] = '\0';
        result[i] = group;
    }

    return result;
}
