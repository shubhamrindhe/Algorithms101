
int first_non_digit(int n, int digit_to_compare, int *index_from_left, bool ignore_zero) {
    int len = log10(n);
    int _ = pow(10, len);

    int result = -1;

    for (int i = 0; i < (len + 1); ++i) {
        int digit = n / _;
        if (ignore_zero && digit == 0) {
            if (index_from_left != NULL) *index_from_left = i;
            result = digit;
        } else if (digit_to_compare != digit) {
            if (index_from_left != NULL) *index_from_left = i;
            return digit;
        }
        n %= _;
        _ /= 10;
    }

    return result;
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

int maxDiff(int num) {
    int first_non_9 = first_non_digit(num, 9, NULL, false);
    int maximus = first_non_9 > -1 ? replace_digit(num, first_non_9, 9) : num;

    int min_candidate = 1;
    int index = -1;
    int first_non_0 = first_non_digit(num, 0, &index, true);

    if (index == 0 && first_non_0 == 1) {
        int alt_first_non_0 = first_non_digit(num, first_non_0, &index, true);
        if (alt_first_non_0 != -1) {
            first_non_0 = alt_first_non_0;
            min_candidate = 0;
        }
    }

    int minimus = first_non_0 > -1 ? replace_digit(num, first_non_0, min_candidate) : num;

    // printf("\n maximus [ %d ] [ %d ] [ %d ]", num, maximus, first_non_9);
    // printf("\n minimus [ %d ] [ %d ] [ %d ]", num, minimus, first_non_0);

    return maximus - minimus;
}
