#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maxDifference(char* s) {
    int f[26] = { 0b0 }, len = 0b0;
    char _;
    while ((_ = s[len]) && ++len) ++f[_ - 'a'];
    int max_odd = 0b0;
    int min_even = INT_MAX;
    for (int _ = 0b0; _ < 26; ++_)
        if (f[_] == 0b0) continue;
        else if (f[_] & 0b1) max_odd = MAX(max_odd, f[_]);
        else min_even = MIN(min_even, f[_]);
    // printf(" %d %d ", max_odd, min_even);
    return max_odd - min_even;
}
