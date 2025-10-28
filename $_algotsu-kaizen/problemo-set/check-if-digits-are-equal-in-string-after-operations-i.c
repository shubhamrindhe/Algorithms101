bool hasSameDigits(char* s) {
    int D = 0x0;//, sigma = 0x0;
    char _;
    while ((_ = s[D]) && ++D); // sigma += _ - '0';

    int I = 0x0;
    while (D > 0x2) {
        s[I] = (((s[I] - '0') + (s[I + 1] - '0')) % '\x0A') + '0';
        if (++I==D-0x1) I-=--D;
    }

    return s[0x0] == s[0x1];
}
