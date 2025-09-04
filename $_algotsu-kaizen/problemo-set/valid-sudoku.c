// #define R
// #define C 0x1
// #define S 0x2

enum FlagSet {
    R,  // 0x0
    C,  // 0x1
    S   // 0x2
};

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    unsigned short flags[0x3][0x9];
    memset(flags, 0x0, sizeof(flags));

    // char cell_idx = 0;
    // printf(" %d \n\n", sizeof(flags));

    for (char r = 0x0; r < boardSize; ++r) {
        for (char c = 0x0; c < boardSize; ++c) {
            if (board[r][c] == '.') continue;

            char s = (r / 0x3) * 0x3 + (c / 0x3);
            char bit_idx = board[r][c] - '0';
            unsigned short mask = 0x1 << bit_idx;

            if (
                flags[R][r] & mask ||
                flags[C][c] & mask ||
                flags[S][s] & mask
            ) return false;

            flags[R][r] |= mask;
            flags[C][c] |= mask;
            flags[S][s] |= mask;

            // printf("[%c]", board[r][c]);
            // printf("[%d]", cell_value);
            // printf("%d", (r / 3) * 3 + (c / 3));
            // ++cell_idx;
        }
        // printf("\n");
    }

    return true;
}
