#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maxCollectedFruits(int** fruits, int fruitsSize, int* fruitsColSize) {
    int N = fruitsSize, LI = N - 0x1;
    register int r, c, l;

    int **dp = (int **)malloc(sizeof(int *) * N);
    for (r = 0; r < N; ++r) dp[r] = (int*)calloc(sizeof(int), N);

    int DIAGONAL = 0;
    for (c = 0; c < N; ++c) DIAGONAL += fruits[c][c];

    int MAX_NE = fruits[0][LI];
    dp[0][LI] = MAX_NE;
    // printf("\n[%d]\n", MAX_NE);
    for (r = 1, l = LI - 1; r < N; ++r, --l) {
        for (c = LI; c >= (l > r ? l : (r + 1)); --c) {
            int maximus = dp[r - 1][c];
            if (c > 0 && maximus < dp[r - 1][c - 1])
                maximus = dp[r - 1][c - 1];
            if (c < LI && maximus < dp[r - 1][c + 1])
                maximus = dp[r - 1][c + 1];

            dp[r][c] = maximus + fruits[r][c];
            MAX_NE = MAX(MAX_NE, dp[r][c]);
            // printf(" %d ", fruits[r][c]);
        }
        // printf("\n");
    }

    int MAX_SW = fruits[LI][0];
    dp[LI][0] = MAX_SW;
    // printf("\n[%d]\n", MAX_SW);
    for (c = 1, l = LI - 1; c < N; ++c, --l) {
        for (r = LI; r >= (l > c ? l : c + 1) ; --r) {
            int maximus = dp[r][c - 1];
            if (r > 0 && maximus < dp[r - 1][c - 1])
                maximus = dp[r - 1][c - 1];
            if (r < LI && maximus < dp[r + 1][c - 1])
                maximus = dp[r + 1][c - 1];

            dp[r][c] = maximus + fruits[r][c];
            MAX_SW = MAX(MAX_SW, dp[r][c]);
            // printf(" %d ", fruits[r][c]);
        }
        // printf("\n");
    }

    for (r = 0; r < N; ++r) free(dp[r]);
    free(dp);

    return MAX_SW + DIAGONAL + MAX_NE ;
}
