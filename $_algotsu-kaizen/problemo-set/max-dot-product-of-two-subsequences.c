int *a, *b;
int n , m;
int dp[501][501];

int solve(int i, int j) {
    if (i == n || j == m) return INT_MIN;
    if (dp[i][j] != INT_MIN) return dp[i][j];

    int product = a[i] * b[j];
    int next = solve(i + 0x1, j + 0x1);
    if (next > 0x0) product += next;

    int skip[0x2] = { solve(i + 0x1, j), solve(i, j + 0x1) };

    int max;
    if (product < skip[0x0])
        max = skip[0x0] > skip[0x1] ? skip[0x0] : skip[0x1];
    else
        max = product > skip[0x1] ? product : skip[0x1];

    return (dp[i][j] = max);
}

int maxDotProduct(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // int dp[nums1Size][nums2Size];
    // memset(dp, 0x0, sizeof dp);

    for (int i = 0x0; i < nums1Size; ++i)
        for (int j = 0x0; j < nums2Size; ++j)
            dp[i][j] = INT_MIN;

    a = nums1, b = nums2;
    n = nums1Size, m = nums2Size;

    return solve(0x0, 0x0);
}
