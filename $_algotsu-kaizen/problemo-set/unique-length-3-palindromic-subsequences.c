// void print(int* list) {
//     printf("\n");
//     for (int i = 0; i < sizeof(list); ++i) printf(" %d ", list[i]);
// }

int countPalindromicSubsequence(char* s) {
    int freq[0b11010] = { 0b0 };
    char _ = '\0';
    int len = 0b0;
    while((_ = s[len]) && ++len) ++freq[_ - 'a'];

    int result = 0b0;
    int palindromes[0b11010] = { -0b1 };
    for (int i = 0; i < 0b11010; ++i) palindromes[i] = -0b1;

    for (int i = 0; i < len; ++i) {
        _ = s[i];
        int char_code = _ - 'a';
        --freq[char_code];

        for (int j = 0; j < 0b11010; ++j) {
            if (palindromes[j] >= 0b0 && freq[j] > 0) {
                int mask = 0b1 << char_code;
                if ((palindromes[j] & mask) == 0) {
                    ++result;
                    palindromes[j] |= mask;
                }
            }
        }

        if (palindromes[char_code] == -0b1) palindromes[char_code] = 0b0;
    }

    return result;
}
