int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int dp[triangleSize][triangleSize];
    memset(dp, sizeof(dp), 0x0);
    dp[0x0][0x0] = triangle[0x0][0x0];

    int result = INT_MAX;

    for (int i = 1; i < triangleSize; ++i) {
        for (int j = 0; j < triangleColSize[i]; ++j) {
            // printf(" %d ", triangle[i][j]);
            if (j == 0) {
                dp[i][j] = dp[i-1][0] + triangle[i][j];
            } else if (j == triangleColSize[i] - 1) {
                dp[i][j] = dp[i-1][j - 1] + triangle[i][j];
            } else {
                int min = dp[i-1][j-1] < dp[i-1][j] ? dp[i-1][j-1] : dp[i-1][j];
                dp[i][j] = min + triangle[i][j];
            }
            // if (result > dp[i][j]) result = dp[i][j];
        }
        // printf("\n");
    }

    // for (int i = 0; i < triangleSize; ++i) {
    //     for (int j = 0; j < triangleColSize[i]; ++j) {
    //         printf(" %d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    for (int j = 0; j < triangleSize; ++j) {
        printf(" %d ", dp[triangleSize - 1][j]);
        if (result > dp[triangleSize - 1][j]) result = dp[triangleSize - 1][j];
    }

    return result;
}
