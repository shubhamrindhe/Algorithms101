#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maxSumDivThree(int* nums, int numsSize) {
    int dp[numsSize][0x3];

    for (int i = 0; i < numsSize; ++i)
        for (int j = 0; j < 0x3; ++j)
            dp[i][j] = INT_MIN / 2;
    dp[0x0][0x0] = 0x0;
    dp[0x0][nums[0x0] % 0x3] = nums[0x0];

    for (int i = 0x1; i < numsSize; ++i) {
        int mod = nums[i] % 0x3;
        int _ = i - 0x1;

        dp[i][0x0] = dp[_][0x0];
        dp[i][0x1] = dp[_][0x1];
        dp[i][0x2] = dp[_][0x2];

        if (mod == 0x0) {
            dp[i][0x0] = MAX(dp[i][0x0], dp[_][0x0] + nums[i]);
            dp[i][0x1] = MAX(dp[i][0x1], dp[_][0x1] + nums[i]);
            dp[i][0x2] = MAX(dp[i][0x2], dp[_][0x2] + nums[i]);
        } else if (mod == 0x1) {
            dp[i][0x0] = MAX(dp[i][0x0], dp[_][0x2] + nums[i]);
            dp[i][0x1] = MAX(dp[i][0x1], dp[_][0x0] + nums[i]);
            dp[i][0x2] = MAX(dp[i][0x2], dp[_][0x1] + nums[i]);
        } else if (mod == 0x2) {
            dp[i][0x0] = MAX(dp[i][0x0], dp[_][0x1] + nums[i]);
            dp[i][0x1] = MAX(dp[i][0x1], dp[_][0x2] + nums[i]);
            dp[i][0x2] = MAX(dp[i][0x2], dp[_][0x0] + nums[i]);
        } else {
            exit(1);
        }
    }

    return MAX(dp[numsSize - 0x1][0x0], 0x0);
}

// 0
// 1
// 2
