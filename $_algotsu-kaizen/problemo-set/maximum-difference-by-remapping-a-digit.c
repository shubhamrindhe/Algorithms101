
int first_non_digit(int n, int digit_to_compare) {
    int len = log10(n);
    int _ = pow(10, len);

    for (int i = 0; i < (len + 1); ++i) {
        int digit = n / _;
        if (digit_to_compare != digit) return digit;
        n %= _;
        _ /= 10;
    }

    return -1;
}

int replace_digit(int n, int digit, int new_digit) {
    int len = log10(n);
    int result = 0;
    int _ = pow(10, len);

    for (int i = 0; i < (len + 1); ++i) {
        int d = n / _;
        result *= 10;
        result += (d == digit) ? new_digit : d;
        n %= _;
        _ /= 10;
    }

    return result;
}

int minMaxDifference(int num) {
    int first_non_9 = first_non_digit(num, 9);
    int first_non_0 = first_non_digit(num, 0);
    int maximus = first_non_9 > -1 ? replace_digit(num, first_non_9, 9) : num;
    int minimus = first_non_0 > -1 ? replace_digit(num, first_non_0, 0) : num;
    // printf("\n maximus [ %d ] [ %d ] [ %d ]", num, maximus, first_non_9);
    // printf("\n minimus [ %d ] [ %d ] [ %d ]", num, minimus, first_non_0);
    return maximus - minimus;
}
