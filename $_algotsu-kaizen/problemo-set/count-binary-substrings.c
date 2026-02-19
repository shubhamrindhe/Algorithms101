static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int countBinarySubstrings(char* s) {
    int f[0x2] = { 0x0, 0x0 };
    char _, prev = '\0';
    int len = 0x0, result = 0x0;

    while ((_ = s[len]) && ++len) {
        bool idx = _ == '1';
        if (prev != _) {
            result += minimus(f[0x0], f[0x1]);
            prev = _;
            f[idx] = 0x0;
        }

        ++f[idx];
    }

    return (result += minimus(f[0x0], f[0x1]));
}
