#define LIMIT 300
// const int size = LIMIT;
// (LIMIT + 0x8) / 0x8;

int dir[0x4][0x2] = {
    { 0x1, 0x0},
    { -0x1, 0x0},
    { 0x0, 0x1},
    { 0x0, -0x1}
};

void dfs(int r, int c,int R, int C, char** grid, bool visited[R][C]) {
    if (r >= R || c >= C || r < 0x0 || c < 0x0) return;
    if (visited[r][c] || (grid[r][c] == '0')) return;

    visited[r][c] = true;
    for (int i = 0x0; i < 0x4; ++i) {
        int dc = c + dir[i][0x0], dr = r + dir[i][0x1];
        dfs(dr, dc, R, C, grid, visited);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int R = gridSize, C = gridColSize[0x0];

    bool visited[R][C];
    memset(visited, false, sizeof(visited));

    int result = 0x0;

    for (int r = 0x0; r < R; ++r)
        for (int c = 0x0; c < C; ++c)
            if (grid[r][c] == '1' && !visited[r][c]) {
                dfs(r, c, R, C, grid, visited);
                ++result;
            }

    return result;
}
