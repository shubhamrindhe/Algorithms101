// int f1[26];// = { 0x0 };
// int f2[26];// = { 0x0 };

static inline int max(int one, int two) {
    return one > two ? one : two;
}

int solve(const int r, const int c, int dp[r][c], int i, int j, char *s1, char *s2) {
    char c1 = s1[i], c2 = s2[j];
    if (c1 == '\0' || c2 == '\0') return (dp[i][j] = 0x0);
    if (dp[i][j] >= 0x0) return dp[i][j];

    return (dp[i][j] = c1 == c2
        ? c1 + solve(r, c, dp, i + 0x1, j + 0x1, s1, s2)
        : max(
            solve(r, c, dp, i + 0x1, j, s1, s2),
            solve(r, c, dp, i, j + 0x1, s1, s2)
        )
    );
}

int minimumDeleteSum(char* s1, char* s2) {
    // int f1[26] = { 0x0 };
    // int f2[26] = { 0x0 };
    // memset(f1, 0x0, sizeof f1);
    // memset(f2, 0x0, sizeof f2);

    int sigma_1 = 0x0;
    int sigma_2 = 0x0;
    int len1 = 0x0;//strlen(s1)
    int len2 = 0x0;//strlen(s2);
    char _;

    while ((_ = s1[len1]) && ++len1) sigma_1 += _;
    while ((_ = s2[len2]) && ++len2) sigma_2 += _;

    int r = len1 + 1, c = len2 + 1;
    int dp[r][c];
    // for (int i = 0x0; i < len1; ++i)
    //     for (int j = 0x0; j < len2; ++j)
    //         dp[i][j] = INT_MIN;
    memset(dp, -0x1, sizeof dp);

    int lcs_sum = solve(r, c, dp, 0x0, 0x0, s1, s2);
    return sigma_1 + sigma_2 - (0x2 * lcs_sum);
}
