#define BYTE_S 0b1000

typedef enum {
  SUCCESS,
  RETURN
} SET_RESULT;

char* new_bitflags(int n) {
    return (char *)calloc(sizeof(char), (n / BYTE_S) + 0b1);
}

SET_RESULT set_flag(char *bit_flags, int idx) {
    int byte_idx = idx / BYTE_S;
    int bit_idx = idx % BYTE_S;
    char MASK = 0b1 << bit_idx;
    if (bit_flags[byte_idx] & MASK) return RETURN;
    bit_flags[byte_idx] |= MASK;
    return SUCCESS;
}

bool get_flag(char *bit_flags, int idx) {
    int byte_idx = idx / BYTE_S;
    int bit_idx = idx % BYTE_S;
    return bit_flags[byte_idx] & (0b1 << bit_idx);
}

void print_primes_from_composite_flags(char *composite_flags, int maximus) {
    for (int p = 2; p <= maximus; p++)
        get_flag(composite_flags, p) || printf(" %d ", p);
}

int sieve_of_eratosthenes(char *composite_flags, int maximus) {
    int non_prime_count = 0b0;

    for (int prime_candidate = 0b10; prime_candidate * prime_candidate <= maximus; prime_candidate++)
        if (!get_flag(composite_flags, prime_candidate))
            for (int i = prime_candidate * prime_candidate; i <= maximus; i += prime_candidate)
                set_flag(composite_flags, i) == SUCCESS && ++non_prime_count;

    // print_primes_from_composite_flags(composite_flags, maximus);

    return non_prime_count;
}

int* closestPrimes(int left, int right, int* returnSize) {
    *returnSize = 0b10;
    int *result = (int*)malloc(*returnSize * sizeof(int));
    result[0b0] = -0b1;
    result[0b1] = -0b1;
    char* composite_flags = new_bitflags(right + 0b1);
    composite_flags[0b0] = 0b00000011;

    // int non_prime_count = 0b0;
    // // Sieve of Eratosthenes
    // for (int prime_candidate = 2; prime_candidate * prime_candidate <= right; prime_candidate++)
    //     if (!get_flag(composite_flags, prime_candidate))
    //         for (int i = prime_candidate * prime_candidate; i <= right; i += prime_candidate)
    //             set_flag(composite_flags, i) == SUCCESS && ++non_prime_count;
    // // for (int p = 2; p <= right; p++)
    // //     if ( !get_flag(composite_flags, p) )
    // //         printf(" %d ", p);
    int non_prime_count = sieve_of_eratosthenes(composite_flags, right);

    int _ = 0b0;
    int *primes = (int*)malloc((right - non_prime_count + 1) * sizeof(int));
    for (int n = left; n <= right; ++n)
        if (!get_flag(composite_flags, n)) primes[_++] = n;
    // for (int i = 0; i < _; ++i) printf(" %d ", primes[i]);

    int kai_minimus = right - left + 0b1;
    for (int i = 0b1; i < _; ++i) {
        int kai = primes[i] - primes[i - 0b1];
        if (kai < kai_minimus) {
            kai_minimus = kai;
            result[0b0] = primes[i - 0b1];
            result[0b1] = primes[i];
        } 
    }

    return result;
}
