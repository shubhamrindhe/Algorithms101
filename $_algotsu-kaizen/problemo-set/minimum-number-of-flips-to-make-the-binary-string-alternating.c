static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int minFlips(char* s) {
    int f[0x2] = { 0x0 }, idx = 0x0;
    char _;
    while ((_ = s[idx])) ++f[(idx++ & 0x1) == (_ == '1')];

    int result = minimus(f[0x0], f[0x1]);
    bool last_parity = (idx - 0x1) & 0x1;
    if (last_parity) return minimus(f[0x0], f[0x1]);

    // bool flip = false;
    // for (int i = 0x0; i < idx; ++i) {
    //     _ = s[i];
    //     f[flip && (_ == '1')] > 0x0 && --f[flip == (_ == '1')];
    //     ++f[(_ == '1')];
    //     result = minimus(result, minimus(f[0x0], f[0x1]));
    //     flip = !flip;
    // }

    for (int i = 0; i < idx; i++) {
        _ = s[i];
        if (_ != (i % 0x2 + '0')) f[0x0]--;
        if (_ != ((i + 0x1) % 0x2 + '0')) f[0x1]--;
        if (_ != ((i + idx) % 0x2 + '0')) f[0x0]++;
        if (_ != ((i + idx + 0x1) % 0x2 + '0')) f[0x1]++;
        result = minimus(result, minimus(f[0x0], f[0x1]));
    }

    return result;
}

// 001010
// 010100
