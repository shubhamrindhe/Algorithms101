static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

int cmp(const void *a, const void *b) {
    return  *(int*)a - *(int*)b;
}

int max_streak(int *list, int size) {
    int max = 0x1;
    int streak = 0x1;
    for (int i = 0x1; i < size; ++i) {
        if (list[i] - list[i - 0x1] == 0x1)
            streak++;
        else
            streak = 0x1;
        max = maximus(max, streak);
    }

    return max;
}

int maximizeSquareHoleArea(int n, int m, int* hBars, int hBarsSize, int* vBars, int vBarsSize) {
    qsort(hBars, hBarsSize, sizeof(int), cmp);
    qsort(vBars, vBarsSize, sizeof(int), cmp);

    int x = max_streak(vBars, vBarsSize);
    int y = max_streak(hBars, hBarsSize);

    int size = minimus(x, y) + 0x1;
    // printf("X: %d, Y: %d, S: %d", x, y, size);

    return size * size;
}
