#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

#define CIDX(_) ((_) - 'a')
#define CIZE 0x1A

// int compare_dec(const void *a, const void *b) {
//     return (*(int*)b - *(int*)a);
// }

void insertion_sort_desc(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int minimumDeletions(char* word, int k) {
    char *_ = word;
    int f[CIZE] = { 0x0 };
    while (*_) ++f[CIDX(*_++)];

    // qsort(f, CIZE, sizeof(int), compare_dec);
    insertion_sort_desc(f, CIZE);

    int result = _ - word;

    for (int i = 0; i < CIZE && f[i]; ++i) {
        int deletions = 0;
        for (int j = 0; j < CIZE && f[j]; ++j)
            if (f[j] < f[i])
                deletions += f[j];
            else if (f[j] > f[i] + k)
                deletions += f[j] - f[i] - k;
        result = MIN(result, deletions);
    }

    return result;
}
