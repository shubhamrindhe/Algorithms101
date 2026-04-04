static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

static inline int adjust(int f) {
    return f > 0x2 ? 0x0 : (f == 0x2 ? -0x1 : 0x1);
}

int numSpecial(int** mat, int matSize, int* matColSize) {
    int R = matSize, C = *matColSize;

    int f1_r = 0x0, f1_c = 0x0;
    int frow[R], fcolumn[C];
    memset(frow, 0x0, sizeof(frow));
    memset(fcolumn, 0x0, sizeof(fcolumn));

    for (int r = 0x0; r < R; ++r)
        for (int c = 0x0; c < C; ++c)
            if (mat[r][c]) {
                f1_r += adjust(++frow[r]);
                f1_c += adjust(++fcolumn[c]);
            }

    // return minimus(f1_r, f1_c);

    int result = 0x0;
    for (int r = 0x0; r < R; ++r)
        for (int c = 0x0; c < C; ++c)
            mat[r][c] && frow[r] == 0x1 && fcolumn[c] == 0x1 && ++result;

    return result;
}
