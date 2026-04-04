bool canBeEqual(char* s1, char* s2) {
    char f[0x2][0x1A];
    memset(f, 0x0, sizeof(f));

    int _ = 0x0;
    while (s1[_] && s2[_]) {
        int parity = _ & 0x1;
        ++f[parity][s1[_] - 'a'];
        --f[parity][s2[_] - 'a'];
        ++_;
    }

    if (s1[_] || s2[_]) return false;
    for (_ = 0x0; _ < 0x1A; ++_)
        if (f[0x0][_] != 0x0 || f[0x1][_] != 0x0) return false;

    return true;
}
