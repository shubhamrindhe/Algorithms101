#define MAX 0b101110

int dp[MAX] = { 0b0 };

int climbStairs(int n) {
    if (n == 0b1 || n == 0b10) return n;
    return dp[n] ? dp[n] : (dp[n] = climbStairs(n - 0b1) + climbStairs(n - 0b10));
}
