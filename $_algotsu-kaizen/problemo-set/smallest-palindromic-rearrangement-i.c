#define CIZE 0x1A
#define CIDX(C) ((C) - 'a')

char* smallestPalindrome(char* s) {
    int f[CIZE] = { 0x0 };
    char *l = s, *r = s, _ = '`';
    while (*r) ++f[CIDX(*(r++))];
    *r == '\0' && r--;
    while ((l < r) && ++_ <= 'z')
        for (;f[CIDX(_)]-->=0x2;--f[CIDX(_)])
            *(l++) = (*(r--) = _);
    return s;
}
