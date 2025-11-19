
enum Axis {
    X = 0b01,
    Y = 0b10,
};

typedef enum {
    EMPTY = '\0',
    GUARD = 'G',
    WALL = 'W',
    GUARDED_HORIZONTALLY = '\x0F',
    GUARDED_VERTICALLY = '\xF0'
} CellType;

int directions[0x4][0x3] = {
    { 0x1, 0x0, X },
    { -0x1, 0x0, X },
    { 0x0, 0x1, Y },
    { 0x0, -0x1, Y }
};

int countUnguarded(int m, int n, int** guards, int guardsSize, int* guardsColSize, int** walls, int wallsSize, int* wallsColSize) {
    char grid[m][n];
    memset(grid, EMPTY, sizeof(grid));
    int result = m * n;

    for (int i = 0x0; i < wallsSize; ++i) {
        int x = walls[i][0x0];
        int y = walls[i][0x1];
        grid[x][y] = WALL;
        --result;
    }

    for (int i = 0x0; i < guardsSize; ++i) {
        int x = guards[i][0x0];
        int y = guards[i][0x1];
        grid[x][y] = GUARD;
        --result;
    }

    for (int i = 0x0; i < guardsSize; ++i) {
        int r = guards[i][0x0];
        int c = guards[i][0x1];

        for (int d = 0x0; d < 0x4; ++d) {
            int dx = directions[d][0x0];
            int dy = directions[d][0x1];
            int mark = directions[d][0x2];

            int x = r + dx, y = c + dy;
            while (x >= 0x0 && x < m && y >= 0x0 && y < n) {
                if (grid[x][y] == WALL || grid[x][y] == GUARD) break;
                if ((grid[x][y] & mark) == mark) break;

                grid[x][y] || --result;
                grid[x][y] |= mark;
                // printf("\n%d %d", x, y);
                x += dx, y += dy;
            }
        }
    }

    return result;
}
