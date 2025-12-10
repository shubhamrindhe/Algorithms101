#define LIMIT 100001
#define MOD 1000000007

int specialTriplets(int* nums, int numsSize) {
    int fr[LIMIT] = { 0x0 };
    int fl[LIMIT] = { 0x0 };
    // memset(fr, 0x0, sizeof(fr));
    // memset(fl, 0x0, sizeof(fl));

    for (int _ = 0x0; _ < numsSize; ++_) ++fr[nums[_]];
    // fl[nums[0x0]] = 1LL;

    long long result = 0x0;

    for (int j = 0x0; j < numsSize; ++j) {
        int J = nums[j];
        --fr[J];

        int Jx2 = J * 0x2;
        if (Jx2 < LIMIT) result = (result + ((long long)fl[Jx2] * fr[Jx2])) % MOD;

        ++fl[J];
    }

    return (int)result;
}
