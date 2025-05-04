#define MAX 0b11111

int dp[MAX] = { 0b0 };

int fib(int n) {
    if (n == 0b1 || n == 0b0) return n;
    return dp[n] ? dp[n] : (dp[n] = fib(n - 1) + fib(n - 2));
}
