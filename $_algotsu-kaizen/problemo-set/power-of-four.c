#define UNO 0b1

bool isPowerOfFour(int n) {
    if (n == 0) return 0;

    int trailing_0s = 0b0;

    while (n) {
        bool trailing_digit = n & UNO;
        n >>= UNO;
        if (trailing_digit)
            if (n) return false;
            else break;
        ++trailing_0s;
    }

    // printf("\n %d %d", trailing_0s, n);
    return !(trailing_0s & UNO);
}
