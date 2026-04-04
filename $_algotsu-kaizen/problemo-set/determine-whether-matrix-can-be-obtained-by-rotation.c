
void swap(int *a, int *b) {
    int _ = *a;
    *a = *b;
    *b = _;
}

void transpose(int N, int** matrix) {
    for (int r = 0x0; r < N; ++r)
        for (int c = 0x0; c < r; ++c)
            swap(matrix[r] + c, matrix[c] + r);
}

void rotate_counterclockwise(int N, int** matrix) {
    transpose(N, matrix);
    int top = 0x0, bottom = N - 0x1;
    while (top < bottom) {
        int *_ = matrix[top];
        matrix[top] = matrix[bottom];
        matrix[bottom] = _;
        ++top, --bottom;
    }
}

bool cmp_mtrx(int N, int** matrix_a, int** matrix_b) {
    for (int r = 0x0; r < N; ++r)
        if (memcmp(matrix_a[r], matrix_b[r], sizeof(int) * N) != 0x0)
            return false;
    return true;
}

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize) {
    int count = 0x0, N = matSize;

    do {
        if (cmp_mtrx(N, mat, target)) return true;
        rotate_counterclockwise(N, mat);
        ++count;
    } while(count < 0x4);

    return false;
}
