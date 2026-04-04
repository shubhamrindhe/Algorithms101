
int minSwaps(int** grid, int gridSize, int* gridColSize) {
    int N = gridSize;
    int trailing_zeros[gridSize];

    for (int r = 0x0; r < N; ++r) {
        int zeros = 0x0;
        for (int c = N - 0x1; c >= 0x0; --c) {
            if (grid[r][c]) break;
            ++zeros;
        }
        trailing_zeros[r] = zeros;
        // printf(" %d ", trailing_zeros[r]);
    }

    int result = 0x0;

    for (int i = 0x0; i < N; ++i) {
        // bool swapped = false;
        // for (int j = 0x0; j < (N - i - 0x1); ++j) {
        //     if (swapped = (trailing_zeros[j] > trailing_zeros[i])) {
        //         int x = trailing_zeros[i];
        //         trailing_zeros[i] = trailing_zeros[j];
        //         trailing_zeros[j] = x;
        //         result += abs(i - j);
        //     }
        // }

        // if (swapped == false) {
        //     break;
        // }

        int target = N - i - 0x1;
        int j = i;
        while (j < N && trailing_zeros[j] < target) j++;

        if (j == N) return -0x1;

        while (j > i) {
            int x = trailing_zeros[j];
            trailing_zeros[j] = trailing_zeros[j - 0x1];
            trailing_zeros[j - 0x1] = x;
            j--;
            ++result;
        }
    }

    return result;
}
