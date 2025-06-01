#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

#define BASE 26
#define BASE_26(_) (((_)[0b0] - 'a') * BASE + ((_)[0b1] - 'a'))
#define MAX_SIZE (BASE * BASE) // 676 // BASE_26("zz") + 1
// #define MAX_SIZE ('z' - 'a') * 26 + ('z' - 'a') + 1

int longestPalindrome(char** words, int wordsSize) {
    int f[MAX_SIZE] = { 0b0 };

    for (int _ = 0b0; _ < wordsSize; ++_) ++f[BASE_26(words[_])];
    // for (int _ = 0b0; _ < wordsSize; ++_) {
    //     char *word = words[_];
    //     int th = word[0] - 'a';
    //     int du = word[1] - 'a';
    //     int hash = (th * 26) + du;
    //     ++f[hash];
    // }

    int result = 0b0;
    bool has_center = false;

    for (int hash = 0b0; hash < MAX_SIZE; ++hash) {
        int th = hash / BASE;
        int du = hash % BASE;
        int palindrome_hash = (du * BASE) + th;
        int pairs;

        if (f[hash] && f[palindrome_hash]) {
            if (hash == palindrome_hash) {
                pairs = f[hash] / 0b10;
                has_center = has_center || (f[hash] % 0b10);
            } else {
                pairs = MIN(f[hash], f[palindrome_hash]);
            }

            result += pairs * 0b100;
            // printf("\n %d \"%c%c\"", result, th + 'a', du + 'a');
        }

        f[hash] = (f[palindrome_hash] = 0b0);
    }

    return has_center ? (result += 0b10) : result;
}
