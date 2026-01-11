static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

int maintain_monotonicity(int stack[][0x2], int *top_ptr, int *start_index, int current_index, int height) {
    int top = *top_ptr;
    int result = 0x0;

    while (top >= 0x0 && stack[top][0x1] > height) {
        int i = stack[top][0x0];
        int h = stack[top][0x1];
        --top;
        int area = h * (current_index - i);
        result = maximus(result, area);
        if (start_index != NULL) *start_index = i;
    }

    *top_ptr = top;
    return result;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    const int R = matrixSize, C = matrixColSize[0x0];
    int stack[C + 0x1][0x2];
    int histogram[C];
    memset(histogram, 0x0, sizeof histogram);

    int result = 0x0;

    for (int r = 0x0; r < R; ++r) {
        int top = -0x1;

        for (int c = 0x0; c < C; ++c) {
            bool has_elevation = matrix[r][c] == '1';

            if (has_elevation)
                histogram[c] = (r > 0x0 ? histogram[c] : 0x0) + 0x1;
            else
                histogram[c] = 0x0;

            int height = histogram[c];
            int start_index = c;
            result = maximus(result, maintain_monotonicity(stack, &top, &start_index, c, height));

            ++top;
            stack[top][0x0] = start_index;
            stack[top][0x1] = height;
        }

        // printf("\n");
        // for (int c = 0x0; c < C; ++c) {
        //     printf(" %d ", histogram[c]);
        // }

        result = maximus(result, maintain_monotonicity(stack, &top, NULL, C, 0x0));
    }

    return result;
}
