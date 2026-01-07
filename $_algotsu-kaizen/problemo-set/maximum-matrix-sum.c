long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    long long result = 0x0;
    register uint8_t flagset = 0b01;
    register int minimus = INT_MAX;

    for (int r = 0x0; r < matrixSize; ++r) {
        register long long rsum = 0x0LL;
        for (int c = 0x0; c < matrixColSize[r]; ++c) {
            int n = matrix[r][c];
            if (n < 0x0) {
                n *= -0x1;
                flagset ^= 0b01;
            } else if (n == 0x0) {
                flagset |= 0b10;
            }

            if (n < minimus) minimus = n;
            rsum += (long long)n;
        }

        result += rsum;
    }

    return flagset ? result : result - (0x2 * minimus);
}
