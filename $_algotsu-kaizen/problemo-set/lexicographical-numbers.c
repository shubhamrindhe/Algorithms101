
void fill(int i, int n, int* list, int* idx) {
    if (i > n) return;
    *(list + (*idx)++) = i;
    fill(i * 10, n, list, idx);
    if (i % 10 < 9) fill(i + 1, n, list, idx);
}

int* lexicalOrder(int n, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * n);
    *returnSize = n;
    int idx = 0;
    fill(1, n, result, &idx);
    return result;
}
