int xor_one_to_n(int n) {
    switch (n % 0x4) {
        case 0x0: return n;
        case 0x1: return 0x1;
        case 0x2: return n + 0x1;
        case 0x3: return 0x0;
    }
    return 0x0;
}

void set_bit(uint64_t flags[], int index) {
    char IDX = index / '@'; // 0x40;
    char idx = index % '@'; // 0x40;
    flags[IDX] |= (uint64_t)0x1 << idx;
}

// bool get(uint64_t flags[], int index) {
//     int IDX = index / 64;
//     int idx = index % 64;
//     return flags[IDX] & (0x1 << idx);
// }

// void print(int rows, int columns, unsigned short matrix[rows][columns]) {
//     for (int r = 0; r < rows; r++) {
//         for (int c = 0; c < columns; c++) {
//             printf("%d ", matrix[r][c]);
//         }
//         printf("\n");
//     }
// }

enum DIMENTION_IDX { R, C };

bool checkValid(int** matrix, int N, int* matrixColSize) {
    // unsigned short hash[N][0x2];
    // memset(hash, 0x0, sizeof(hash));

    // register int r, c;
    // for (r = 0; r < N; ++r)
    //     for (c = 0; c < N; ++c)
    //         hash[r][R] += matrix[r][c], hash[c][C] += matrix[r][c];

    // // print(N, 2, hash);
    // unsigned short sigma_n = N * (N + 1) / 2;
    // for (r = 0; r < N; ++r)
    //     if (hash[r][R] != sigma_n || hash[r][C] != sigma_n) return false;

    // return true;

    uint64_t hash[0x2][N][0x2];
    memset(hash, 0x0, sizeof(hash));

    register int r, c;
    for (r = 0x0; r < N; ++r)
        for (c = 0x0; c < N; ++c)
            set_bit(hash[R][r], matrix[r][c]),
            set_bit(hash[C][c], matrix[r][c]);

    uint64_t expected_line_hash[0x2];
    for (r = 0x1; r <= N; ++r) set_bit(expected_line_hash, r);

    if (memcmp(hash[R], hash[C], sizeof(hash[0x0])) != 0x0) return false;
    for (r = 0x0; r < N; ++r)
        if (memcmp(hash[R][r], expected_line_hash, sizeof(expected_line_hash)) != 0x0) return false;

    return true;
}
