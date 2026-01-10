
static inline int max(int one, int two) {
    return one > two ? one : two;
}

int dp[1001][1001];

int solve(int i, int j, char *s1, char *s2) {
    char c1 = s1[i], c2 = s2[j];

    if (c1 == '\0' || c2 == '\0') return dp[i][j] = 0x0;
    if (dp[i][j] >= 0x0) return dp[i][j];

    // printf("\n [%c] %c ", c1, c2);
    // if (c1 == c2)
    //     dp[i][j] = 0x1 + solve(i + 1, j + 1, s1, s2);
    // else
    //     dp[i][j] = max(solve(i + 1, j, s1, s2), solve(i, j + 1, s1, s2));

    return (dp[i][j] = c1 == c2
        ? 0x1 + solve(i + 0x1, j + 0x1, s1, s2)
        : max(solve(i + 0x1, j, s1, s2), solve(i, j + 0x1, s1, s2)));
}

int longestCommonSubsequence(char* text1, char* text2) {
    // for (int i = 0x0; i < 1000; ++i)
    //     for (int j = 0x0; j < 1000; ++j)
    //         dp[i][j] = INT_MIN;
    memset(dp, -0x1, sizeof dp);

    // for (int i = 0x0; i < strlen(text1); ++i) {
    //     for (int j = 0x0; j < strlen(text2); ++j)
    //         printf(" %d ", dp[i][j]);
    //     printf("\n");
    // }
    return solve(0x0, 0x0, text1, text2);
}
