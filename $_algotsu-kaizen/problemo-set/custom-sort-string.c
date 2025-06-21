
#define CIDX(_) ((_) - 'a')
#define CIZE 0x1A

char* customSortString(char* order, char* s) {
    register char *_ = s, c, i, ci;
    unsigned int f[CIZE] = { 0x0U };
    while (*_) ++f[CIDX(*_++)];

    _ = s;
    for (ci = CIDX((c = order[(i = 0x0)])); order[i]; ci = CIDX((c = order[++i])))
        while (f[ci]) (*_++ = c) && --f[ci];
    for (ci = CIDX((c = 'a')); c <= 'z'; ci = CIDX(++c))
        while (f[ci]) (*_++ = c) && --f[ci];

    return s;
}
