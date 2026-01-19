typedef struct Data {
    int row, column, tl_br, tr_bl;
} Data;

// void print_grid(int R, int C, Data grid[R][C]) {
//     for (int r = 0; r < R; ++r) {
//         printf("\n");
//         for (int c = 0; c < C; ++c) {
//             printf(" %d ", grid[r][c].tl_br);
//         }
//     }
// }

bool is_magic_square(int R, int C, Data grid[R][C], int x, int y, int size) {
    int X = x + size - 0x1;
    int Y = y + size - 0x1;
    if (X >= C || Y >= R) return false;

    int tl_br = grid[Y][X].tl_br;
    int tr_bl = grid[Y][x].tr_bl;

    // printf("[ %d, %d ] - [ %d, %d ]  \n", x, y, X, Y);
    // printf("[ %d ] [ %d ]\n", tl_br, tr_bl);
    if (x > 0 && y > 0) tl_br -= grid[y - 1][x - 1].tl_br;
    if ((X + 1) < C && y > 0x0) tr_bl -= grid[y - 0x1][X + 0x1].tr_bl;
    // printf("[ %d ] [ %d ]\n", tl_br, tr_bl);

    if (tl_br != tr_bl) return false;

    for (int i = 0; i < size; ++i) {
        int sigma_column = grid[Y][x + i].row - (y > 0 ? grid[y - 1][x + i].row : 0);
        int sigma_row = grid[y + i][X].column - (x > 0 ? grid[y + i][x - 1].column : 0);
        if (sigma_column != tl_br || sigma_row != tl_br) return false;
    }

    return true;
}

int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
    int R = gridSize, C = *gridColSize;
    Data prefix_sum[R][C];
    memset(prefix_sum, 0x0, sizeof prefix_sum);

    for (int r = 0x0; r < R; ++r)
        for (int c = 0x0; c < C; ++c) {
            int _ = grid[r][c];
            prefix_sum[r][c].row = _;
            prefix_sum[r][c].column = _;
            prefix_sum[r][c].tl_br = _;
            prefix_sum[r][c].tr_bl = _;
            if (r > 0) prefix_sum[r][c].row += prefix_sum[r - 0x1][c].row;
            if (c > 0) prefix_sum[r][c].column += prefix_sum[r][c - 0x1].column;
            if (r > 0 && c > 0) prefix_sum[r][c].tl_br += prefix_sum[r - 0x1][c - 0x1].tl_br;
            if (r > 0 && (c + 0x1) < C) prefix_sum[r][c].tr_bl += prefix_sum[r - 0x1][c + 0x1].tr_bl;
        }

    // print_grid(R, C, prefix_sum);
    int result = 0x1;

    for (int r = 0; r + result < R; ++r)
        for (int c = 0; c + result < C; ++c)
            for (int size = result + 1; r + size <= R && c + size <= C; ++size)
                if (is_magic_square(R, C, prefix_sum, c, r, size))
                    if (size > result) result = size;

    return result;
}
