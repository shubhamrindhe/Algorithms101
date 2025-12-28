int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int result = 0x0;

    // for (int r = 0x0; r < gridSize; ++r)
    //     for (int c = 0x0; c < gridColSize[r]; ++c)
    //         if (grid[r][c] < 0x0)
    //             printf("\n %d %d", grid[r][c], C - c);
    //             ++result;

    int R = gridSize, C = gridColSize[0x0];
    int r = gridSize - 0x1, c = 0x0;

    while (r >= 0x0 && c < C)
        if (grid[r][c] < 0x0) result += C - c, --r;
        else ++c;

    return result;
}

// [
//     [4,3,2,-1],
//     [3,2,1,-1],
//     [1,1,-1,-2],
//     [-1,-1,-2,-3]
// ]
