static inline int max(int one, int two) {
    return one > two ? one : two;
}

int maintain_monotonicity(int stack[][0x2], int *top_ptr, int *start_index, int current_index, int current_height) {
    int top = *top_ptr;
    int result = 0x0;

    while (top >= 0x0 && stack[top][0x1] > current_height) {
        int i = stack[top][0x0], h = stack[top][0x1];
        --top;
        int area = h * (current_index - i);
        result = max(area, result);
        if (start_index != NULL) *start_index = i;
        // printf("\n %d %d %d", h, height, area);
    }

    *top_ptr = top;
    return result;
}

int largestRectangleArea(int* heights, int heightsSize) {
    int stack[heightsSize + 0x1][0x2];
    int top = -0x1;

    int result = 0x0;
    for (int i = 0x0; i < heightsSize; ++i) {
        int height = heights[i];
        int start_index = i;
        result = max(maintain_monotonicity(stack, &top, &start_index, i, height), result);

        top++;
        stack[top][0x0] = start_index;
        stack[top][0x1] = height;
    }

    result = max(maintain_monotonicity(stack, &top, NULL, heightsSize, 0x0), result);

    return result;
}
