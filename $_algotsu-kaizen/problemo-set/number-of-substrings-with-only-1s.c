int MOD = 1000000007;

int numSub(char* s) {
    long long result = 0x0, count = 0x0;
    int len = 0x0;
    char _;

    while ((_ = s[len]) && ++len) {
        if (_ == '1' && ++count) continue;
        result = (result + ((count + 1) * count) / 0x2) % MOD;
        count = 0x0;
    }

    return (int)((result + ((count + 1) * count) / 0x2) % MOD);
}

// 1 - 1
// 11 - 3
// 111 - 1,1,1, 11,11, 111 = 6
// 1111 - 1,1,1,1 11,11,11, 111,111, 1111 = 10
