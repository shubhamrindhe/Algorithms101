const char digits[] = "0123456789";

bool is_palindrome(char *string, int length) {
    char *l = string, *r = string + length - 1;
    while (l < r) if (*(l++) != *(r--)) return false;
    return true;
}

void convert_to_base(long long n, int base, const char char_map[], char data[], int *data_len) {
    *data_len = 0x0;
    while (n > 0) {
        // char c = (n % base) + '0';
        char c = char_map[n % base];
        data[(*data_len)++] = c;
        n /= base;
    }
    data[(*data_len)] = '\0';
}

long long reverse_number(long long num) {
    long long reversed = 0x0;
    while (num > 0) {
        int digit = num % 0xA;
        reversed = reversed * 0xA + digit;
        num /= 0xA;
    }
    return reversed;
}

// THE NumericPalindromeGenerator
typedef struct {
    int length;
    long long range_start;
    long long range_end;
    long long severed_half;
    long long severed_half_maximus;
} NumericPalindromeGenerator;

NumericPalindromeGenerator* new_numeric_palindrome_generator() {
    NumericPalindromeGenerator *npg = (NumericPalindromeGenerator *)calloc(sizeof(NumericPalindromeGenerator), 0x1);
    // npg->length = 0x0;
    // npg->range_start = 0;
    // npg->range_end = 0;
    // npg->severed_half = 0;
    // npg->severed_half_maximus = 0;
    return npg;
}

long long sever(long long n, int len) {
    return n / pow(0xA, len / 2);
}

void setup_for_length(NumericPalindromeGenerator *palindromeGenerator, int length) {
    palindromeGenerator->length = length;
    palindromeGenerator->range_start = pow(0xA, length - 1);
    palindromeGenerator->range_end = pow(0xA, length) - 1;
    palindromeGenerator->severed_half = sever(palindromeGenerator->range_start, length);
    palindromeGenerator->severed_half_maximus = sever(palindromeGenerator->range_end, length);
}

long long generate_palindrome(NumericPalindromeGenerator *palindromeGenerator) {
    long long prefix = palindromeGenerator->severed_half;
    if (palindromeGenerator->length == 1) return prefix;
    long long suffix = reverse_number(palindromeGenerator->length & 0b1 ? prefix / 0xA : prefix);
    long long palindrome = prefix * pow(0xA, palindromeGenerator->length / 0b10) + suffix;
    return palindrome;
}

long long next(NumericPalindromeGenerator *palindromeGenerator) {
    long long palindrome = generate_palindrome(palindromeGenerator);
    if (palindromeGenerator->severed_half < palindromeGenerator->severed_half_maximus)
        palindromeGenerator->severed_half++;
    else
        setup_for_length(palindromeGenerator, palindromeGenerator->length + 1);
    return palindrome;
}

long long kMirror(int k, int n) {
    NumericPalindromeGenerator* palindromeGenerator = new_numeric_palindrome_generator();
    setup_for_length(palindromeGenerator, 0x1);

    long long result = 0x0LL;
    char base_k_string[0x20];
    int base_k_string_length, count = 0x0;

    while (count < n) {
        long long candidate = next(palindromeGenerator);
        convert_to_base(candidate, k, digits, base_k_string, &base_k_string_length);
        if (is_palindrome(base_k_string, base_k_string_length)) {
            ++count;
            result += candidate;
        }

        // printf("\n [  %d  ] [  %s  ]", candidate, baseKdata);
    }

    free(palindromeGenerator);

    return result;
}
