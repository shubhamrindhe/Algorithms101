static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

int dir[0x4][0x2] = {
    { 0x1, 0x0},
    { -0x1, 0x0},
    { 0x0, 0x1},
    { 0x0, -0x1}
};

int dfs(int r, int c,int R, int C, int** grid, bool visited[R][C]) {
    if (r >= R || c >= C || r < 0x0 || c < 0x0) return 0x0;
    if (visited[r][c] || (grid[r][c] == 0x0)) return 0x0;

    visited[r][c] = true;
    int area = 0x1;
    for (int i = 0x0; i < 0x4; ++i) {
        int dc = c + dir[i][0x0], dr = r + dir[i][0x1];
        area += dfs(dr, dc, R, C, grid, visited);
    }

    return area;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int R = gridSize, C = gridColSize[0x0];

    bool visited[R][C];
    memset(visited, false, sizeof(visited));
    int result = 0x0;

    for (int r = 0x0; r < R; ++r)
        for (int c = 0x0; c < C; ++c)
            result = maximus(result, dfs(r, c, R, C, grid, visited));

    return result;
}
