
enum { A, E, I, O, U, a, e, i, o, u };
char vovels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

short vovel_idx(char _) {
    switch (_) {
        case 'A': return A;
        case 'E': return E;
        case 'I': return I;
        case 'O': return O;
        case 'U': return U;
        case 'a': return a;
        case 'e': return e;
        case 'i': return i;
        case 'o': return o;
        case 'u': return u;
    }
    return -0x1;
}

char* sortVowels(char* s) {
    int f[0xA] = { 0x0 }, len = 0x0, idx;
    char _;

    while ((_ = s[len]) && ++len) {
        idx = vovel_idx(_);
        if (idx == -0x1) continue;
        ++f[idx];
    }

    idx = 0x0;
    for (int i = 0x0; i < len; ++i) {
        if (vovel_idx(s[i]) == -0x1) continue;
        while (!f[idx] && ++idx);
        s[i] = vovels[idx];
        --f[idx];
    }

    return s;
}
