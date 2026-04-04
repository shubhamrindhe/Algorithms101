#define MOD 1000000007u

// const long long MOD = (10e9 + 7);
// uint64_t safe_shift(uint64_t x, int shifts) {
// }

int concatenatedBinary(int n){
    uint64_t result = 0x1;
    int _ = 0x2, len = 0x1;

    while (_ <= n) {
        (_ & (_ - 0x1)) || ++len;
        // printf("\n %d %d", _, len);
        result = (((result << len) % MOD) + _) % MOD;
        _++;
    }

    return (int)result;
}
