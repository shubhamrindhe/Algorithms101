#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef struct { int x, y; } Point;

int minimumArea(int** grid, int gridSize, int* gridColSize) {
    Point minimus = { INT_MAX, INT_MAX }, maximus = { INT_MIN, INT_MIN };

    for (int x = 0; x < gridSize; ++x)
        for (int y = 0; y < gridColSize[x]; ++y)
            if (grid[x][y]) {
                if (minimus.x > x) minimus.x = x;
                if (minimus.y > y) minimus.y = y;
                if (maximus.x < x) maximus.x = x;
                if (maximus.y < y) maximus.y = y;
            }

    // printf("\nminimus: (%d, %d) ", minimus.x, minimus.y);
    // printf("\nmaximus: (%d, %d) ", maximus.x, maximus.y);
    if (
        minimus.x == INT_MAX || minimus.y == INT_MAX
    || // REDUNDANT
        maximus.x == INT_MIN || maximus.y == INT_MIN
    ) return 0;

    return (maximus.y - minimus.y + 1) * (maximus.x - minimus.x + 1);
}
