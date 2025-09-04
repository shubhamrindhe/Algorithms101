#define I 0b1

long long flowerGame(int n, int m) {
    // long long result = 0LL;
    // for (int X = I; X <= n; ++X)
    //     for (int Y = I; Y <= m; ++Y)
    //         ((I & X) ^ (Y & I)) && ++result;
    // return result;

    // long long X_E = (n) / 2,
    // X_O = (n + 1) / 2,
    // Y_E = (m) / 2,
    // Y_O = (m + 1) / 2;

    // return X_E * Y_O + X_O + Y_E;
    return (long long)m * n / 2;
}
