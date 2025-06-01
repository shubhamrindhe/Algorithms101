int totalNumbers(int* digits, int digitsSize) {
    int f[0b1011] = { 0b0 };
    for (int _ = 0b0; _ < digitsSize; ++_) ++f[digits[_]];

    int result = 0b0;
    bool _ = true;
    for (int n = 0b1100100; n < 0b1111101000; n += 0b10) {
        int h = n / 0b1100100, d = (n % 0b1100100) / 0b1010, u = n % 0b1010;
        _ = true;
        if (--f[h] < 0b0) _ = false;
        if (--f[d] < 0b0) _ = false;
        if (--f[u] < 0b0) _ = false;
        ++f[h];
        ++f[d];
        ++f[u];
        if (_) ++result;
    }

    return result;
}
