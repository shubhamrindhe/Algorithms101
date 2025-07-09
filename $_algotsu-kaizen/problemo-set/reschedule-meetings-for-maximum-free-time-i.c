#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maxFreeTime(int eventTime, int k, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {
    int n = startTimeSize + 1;
    int *gaps = (int*)calloc(sizeof(int), n);

    gaps[0] = startTime[0];
    for (int i = 1; i < startTimeSize; ++i) gaps[i] = startTime[i] - endTime[i - 1];
    gaps[startTimeSize] = eventTime - endTime[endTimeSize - 1];
    // for (_ = 0; _ < startTimeSize + 1; ++_) printf(" %d ", gaps[_]);

    int window = k + 1, sum = 0;
    for (int i = 0; i < window; ++i) sum += gaps[i];

    int result = sum;
    for (int i = window; i < n; ++i) {
        sum += gaps[i] - gaps[i - window];
        result = MAX(result, sum);
    }
    free(gaps);

    return result;
}
