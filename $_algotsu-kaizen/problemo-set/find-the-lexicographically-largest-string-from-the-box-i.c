#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

char* answerString(char* word, int numFriends) {
    int N = strlen(word);
    int max_substr_len = N - numFriends + 0b1;
    char *result = (char *)calloc(sizeof(char), max_substr_len + 0b1);

    if (numFriends == 1) {
        strcpy(result, word);
        return result;
    }

    int *idx_list = (int *)malloc(sizeof(int) * N);
    int max_idx_len = 0b0;
    char max_c = '\0';

    for (int i = 0; i < N; ++i) {
        if (max_c < word[i]) {
            max_c = word[i];
            max_idx_len = 0b0;
        }
        if (max_c == word[i]) idx_list[max_idx_len++] = i;
    }

    // int idx = -1;
    for (int i = 0b0; i < max_idx_len; ++i) {
        int start_offset = idx_list[i];
        // int available_length = MIN(N, start_offset + max_substr_len);
        // printf("\n %d %d", start_offset, available_length);
        // if (i == 0) {
        //     strncpy(result, word + start_offset, available_length);
        //     idx = i;
        //     continue;
        // }
        if (strncmp(result, word + start_offset, max_substr_len) < 0b0)
            strncpy(result, word + start_offset, max_substr_len);
    }

    free(idx_list);

    return result;
}
