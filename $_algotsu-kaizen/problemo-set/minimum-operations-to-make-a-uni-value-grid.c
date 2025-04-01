
int compare(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int minOperations(int** grid, int gridSize, int* gridColSize, int x) {
    int size = gridSize * (*gridColSize);
    int *list = (int *)malloc(sizeof(int) * size);
    int idx = 0, last = grid[0][0];

    for (int i = 0; i < gridSize; ++i)
        for (int j = 0; j < *gridColSize; ++j) {
            list[idx++] = grid[i][j];
            int kai = grid[i][j] - last;
            if (kai % x) return -1;
            last = grid[i][j];
        }

    qsort(list, size, sizeof(int), compare);

    // for (int i = 0; i < size; ++i) printf(" %d ", list[i]);
    int centrum = list[(size / 2)];
    int result = 0;
    for (int i = 0; i < size; ++i) {
        int kai = list[i] > centrum ? list[i] - centrum : centrum - list[i];
        result += kai / x;
    }

    return result;
}
