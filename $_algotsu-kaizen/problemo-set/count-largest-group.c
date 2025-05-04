#define MAX 0b1001 * 0b100 + 0b10

int _(int x) {
    int sigma = 0b0;
    while (x) {
        sigma += x % 0b1010;
        x /= 0b1010;
    }
    return sigma;
}

int countLargestGroup(int n) {
    int dp[MAX] = { 0b0 };
    int maximus = 0b0;
    for (int i = 0b1; i <= n; ++i) {
        int sum = _(i);
        ++dp[sum];
        if (maximus < dp[sum]) maximus = dp[sum];
    }

    int result = 0b0;
    for (int i = 0b1; i < MAX; ++i) dp[i] == maximus && ++result;
    return result;
}
