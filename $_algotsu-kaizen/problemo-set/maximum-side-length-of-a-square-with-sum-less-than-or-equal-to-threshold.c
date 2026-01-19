// void print_grid(int R, int C, int grid[R][C]) {
//     for (int r = 0; r < R; ++r) {
//         printf("\n");
//         for (int c = 0; c < C; ++c) {
//             printf(" %d ", grid[r][c]);
//         }
//     }
// }

static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int sum_of_elements(int R, int C, int grid[R][C], int x, int y, int size) {
    int X = x + size - 0x1;
    int Y = y + size - 0x1;
    if (X >= C || Y >= R) return -0x1;

    int sum = 0x0;
    // for (int r = y; r <= Y; ++r) {
    //     int row_sum = grid[r][X];
    //     if (x > 0) row_sum -= grid[r][x - 0x1];
    //     sum += row_sum;
    // }
    sum = grid[Y][X];
    if (x > 0x0) sum -= grid[Y][x - 0x1];
    if (y > 0x0) sum -= grid[y - 0x1][X];
    if (x > 0x0 && y > 0x0) sum += grid[y - 0x1][x - 0x1];
    return sum;
}

int maxSideLength(int** mat, int matSize, int* matColSize, const int threshold) {
    int R = matSize, C = *matColSize;
    int prefix_sum[R][C];
    // memset(prefix_sum, 0x0, sizeof prefix_sum);
    int l = 1, r = minimus(R, C);

    for (int r = 0x0; r < R; ++r)
        for (int c = 0x0; c < C; ++c) {
            prefix_sum[r][c] = mat[r][c];
            if (r > 0x0) prefix_sum[r][c] += prefix_sum[r - 0x1][c];
            if (c > 0x0) prefix_sum[r][c] += prefix_sum[r][c - 0x1];
            if (r > 0x0 && c > 0x0) prefix_sum[r][c] -= prefix_sum[r - 0x1][c - 0x1];
            if (prefix_sum[r][c] <= threshold) l = maximus(l, minimus(r, c));
        }

    // print_grid(R, C, prefix_sum);
    int result = 0x0;

    // for (int r = 0x0; (r + result) < R; ++r)
    //     for (int c = 0x0; (c + result) < C; ++c)
    //         for (int size = result + 0x1; (r + size) <= R && (c + size) <= C; ++size)
    //             if (sum_of_elements(R, C, prefix_sum, c, r, size) <= threshold)
    //                 if (size > result) result = size;

    while (l <= r) {
        int m = l + (r - l) / 2;
        bool found_square = false;

        for (int r = 0x0; (r + m) <= R; ++r) {
            for (int c = 0x0; (c + m) <= C; ++c) {
                if (sum_of_elements(R, C, prefix_sum, c, r, m) <= threshold) {
                    found_square = true;
                    break;
                }
            }

            if (found_square) break;
        }

        if (found_square) {
            result = maximus(result, m);
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return result;
}
