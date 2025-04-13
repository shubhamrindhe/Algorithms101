
#define MOG 1000000007LL

long long fast_exp(long long b, long long p) {
    if (p == 0b0L) return 0b1L;
    if (p % 0b10L) return (b * fast_exp(b, p - 0b1L)) % MOG;
    else {
        long long severed_value = fast_exp(b, p / 0b10L);
        return (severed_value * severed_value) % MOG;
    }
}

int countGoodNumbers(long long n) {
    long long even = n / 2LL;
    long long odd = (n + 1LL) / 2LL;
    // printf(" %d %d \n\n", odd, even);
    // printf(" %f %f \n\n", floor(n / 2), ceil(n / 2));
    // printf(" %f %f \n\n", (float)(n / 2), (float)(n / 2));
    // printf(" %d %d ", (int)pow(4, odd), (int)pow(5, even));
    return (int) ( ( fast_exp(5LL, odd) * fast_exp(4LL, even) ) % MOG );
}
