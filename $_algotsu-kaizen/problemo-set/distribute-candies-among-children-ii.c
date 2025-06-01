#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

long long distributeCandies(int n, int limit) {
    long long result = 0;

    // for (int i = 0; i <= MIN(n, limit); ++i)
    //     for (int j = 0; j <= MIN(n - i, limit); ++j)
    //         for (int k = 0; k <= MIN(n - i - j, limit); ++k)
    //             (i + j + k) == n && ++result;

    for (int first = 0; first <= MIN(n, limit); ++first) {
        int second_and_third = n - first;
        if (second_and_third > (limit * 2)) continue;
        int second_min = MAX(second_and_third - limit, 0);
        int second_max = MIN(second_and_third, limit);
        result += second_max - second_min + 1;
    }

    return result;
}
