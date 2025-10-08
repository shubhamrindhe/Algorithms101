int dirs[4][2] = {
    {-0x1, 0x0},
    {+0x1, 0x0},
    {0x0, -0x1},
    {0x0, +0x1}
};

bool dfs(int** grid, int N, bool visited[][N], int x, int y, int t) {
    if (grid[x][y] > t) return false;
    if (x == N - 0x1 && y == N - 0x1) return true;

    visited[x][y] = true;

    for (int i = 0x0; i < 0x4; ++i) {
        int nx = x + dirs[i][0x0], ny = y + dirs[i][0x1];
        if (
            nx >= 0x0 && nx < N &&
            ny >= 0x0 && ny < N &&
            (!visited[nx][ny]) &&
            dfs(grid, N, visited, nx, ny, t)
        ) return true;
    }

    return false;
}

int swimInWater(int** grid, int gridSize, int* gridColSize) {
    int N = gridSize;
    bool visited[N][N];
    int l = grid[0x0][0x0] > grid[N-1][N-1] ? grid[0x0][0x0] : grid[N - 1][N - 1], r = N * N - 0x1;

    while (l < r) {
        int m = (l + r) / 0x2;
        memset(visited, false, sizeof(visited));
        if (dfs(grid, N, visited, 0x0, 0x0, m))
            r = m;
        else
            l = m + 0x1;
    }

    return l;
}
