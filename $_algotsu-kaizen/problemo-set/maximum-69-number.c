#define DASH 10

int maximum69Number(int num) {
    int len = log10(num), div = pow(DASH, len);
    int result = 0;

    for (int i = len; i >= 0; --i, div /= DASH) {
        int digit = num / div;
        num %= div;
        result *= DASH;

        if (digit == 6) {
            // printf("\n [%d] %d ", num, div);
            result += 9;
            result *= div;
            result += num;
            break;
        }

        // result += digit == 6 ? 9 : digit;
        result += digit;
        // printf("\n %d ", digit);
    }

    return result;
}
