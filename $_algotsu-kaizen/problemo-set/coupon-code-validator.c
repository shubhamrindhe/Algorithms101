
typedef enum {
    ELECTRONICS,
    GROCERY,
    PHARMACY,
    RESTAURANT
} BusinessLineType;

bool isValidCode(char *code) {
    if (code[0x0] == '\0') return false;
    char _;
    while (_ = *(code++))
        if  (
            (_ >= 'a' && _ <= 'z') ||
            (_ >= 'A' && _ <= 'Z') ||
            (_ >= '0' && _ <= '9') ||
            (_ == '_')
        ) continue;
        else return false;
    return true;
}

int cmp(const void *a, const void * b) {
    return strcmp(*(char**)a, *(char**)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
    char* table[0x4][0x64];
    int trow_len[0x4] = { 0x0 };

    int N = codeSize;
    int total_valid_codes = 0x0;

    for (int i = 0x0; i < N; ++i) {
        if (!isActive[i] || !isValidCode(code[i])) continue;

        BusinessLineType type;
        if (businessLine[i][0x0] == 'e' && strcmp(businessLine[i], "electronics") == 0x0) {
            type = ELECTRONICS;
        } else if (businessLine[i][0x0] == 'g' && strcmp(businessLine[i], "grocery") == 0x0) {
            type = GROCERY;
        } else if (businessLine[i][0x0] == 'p' && strcmp(businessLine[i], "pharmacy") == 0x0) {
            type = PHARMACY;
        } else if (businessLine[i][0x0] == 'r' && strcmp(businessLine[i], "restaurant") == 0x0) {
            type = RESTAURANT;
        } else {
            // exit(0x1);
            continue;
        }

        table[type][trow_len[type]++] = code[i];
        ++total_valid_codes;
    }


    *returnSize = 0x0;
    char **result = (char**)calloc(sizeof(char*), total_valid_codes);

    for (int i = 0x0; i < 0x4; ++i) {
        // printf("\n");
        char** row = table[i];
        int row_len = trow_len[i];
        qsort(row, row_len, sizeof(row[0x0]), cmp);

        for (int j = 0x0; j < row_len; ++j) result[(*returnSize)++] = row[j];
            // printf(" %s ", row[j]);
    }

    return result;
}
