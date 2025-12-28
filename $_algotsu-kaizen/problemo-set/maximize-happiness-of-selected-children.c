int compare(const void *a, const void *b) {
    int A = *(int*)a;
    int B = *(int*)b;
    return B - A;
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), compare);

    long long result = 0x0;

    for (int i = 0x0; i < k; ++i) {
        int kai = happiness[i] - i;
        if (kai <= 0x0) break;
        result += kai;
    }

    return result;
}
