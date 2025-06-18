#define CIZE 0x1A
#define CIDX(C) ((C) - 'a')

char* smallestPalindrome(char* s) {
    int f[CIZE] = { 0b0 };
    char *l = s, *r = s, _ = '`';
    while (*r) ++f[CIDX(*(r++))];
    *r == '\0' && r--;
    while ((++_ <= 'z') && (l < r)) //for (int i = 0b0; i < f[CIDX(_)]; i += 0b10) *(l++) = (*(r--) = _);
        for (;f[CIDX(_)]-->0x0;--f[CIDX(_)]) *(l++) = (*(r--) = _);
    return s;
}
