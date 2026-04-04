static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

// 01010... -> (EE, OO)
// 10101... -> (EO, OE)
int minOperations(char* s) {
    int f[0x2] = { 0x0 }, idx = 0x0;
    char _;

    while ((_ = s[idx])) {
        bool idx_parity = (idx & 0x1);
        bool val_parity = (_ == '1');
        ++f[idx_parity == val_parity];
        ++idx;
    }

    return minimus(f[0x0], f[0x1]);
}
