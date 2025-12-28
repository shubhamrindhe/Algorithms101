enum IDX { N, Y };

int bestClosingTime(char* customers) {
    int len = 0x0;
    char _;

    int f[0x2] = { 0x0, 0x0 };
    while ((_ = customers[len]) && ++len) ++f[_ == 'Y'];

    int min_penalty = len;
    int result = len;
    int t[0x2] = { 0x0, 0x0 };

    for (int i = 0x0; i <= len; ++i) {
        _ = customers[i];
        int penalty;

        penalty = t[N] + (f[Y] - t[Y]);
        ++t[_ == 'Y'];
        // if (_ == 'Y') {
        //     penalty = t[N] + (f[Y] - t[Y]);
        //     ++t[Y];
        // } else {
        //     penalty = t[N] + (f[Y] - t[Y]);
        //     ++t[N];
        // }

        // printf("\n %d ( %d, %d, %d ) => %d ", i, t[N], f[Y], t[Y], penalty);
        // printf("\n %d => %d ", i, penalty);

        if (penalty < min_penalty) {
            min_penalty = penalty;
            result = i;
        }
    }

    return result;
}
