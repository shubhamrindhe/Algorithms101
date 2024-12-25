#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

void eval_column(int** dp, int** grid, int gridSize, int* gridColSize, int col) {
    for (int r = 0; r < gridSize; ++r) {
        int val = grid[r][col];
        int max = -1;

        if (r - 1 >= 0 && grid[r - 1][col + 1] > val)
            max = MAX(dp[r - 1][col + 1], max);

        if (grid[r][col + 1] > val)
            max = MAX(dp[r][col + 1], max);

        if (r + 1 < gridSize && grid[r + 1][col + 1] > val)
            max = MAX(dp[r + 1][col + 1], max);

        dp[r][col] = (max == -1) ? 0 : max + 1;
    }
}

int maxMoves(int** grid, int gridSize, int* gridColSize) {
    int** dp = (int **)malloc(sizeof(int *) * gridSize);

    for (int i = 0; i < gridSize; ++i) dp[i] = (int *)malloc(sizeof(int) * gridColSize[i]);
    for (int r = 0; r < gridSize; ++r)
        for (int c = 0; c < gridColSize[r]; ++c)
            dp[r][c] = 0;

    for (int c = gridColSize[0] - 2; c >= 0; --c)
        eval_column(dp, grid, gridSize, gridColSize, c);

    int result = 0;
    for (int r = 0; r < gridSize; ++r)
        result = MAX(dp[r][0b0], result);

    for (int i = 0; i < gridSize; ++i) free(dp[i]);
    free(dp);

    return result;
}
