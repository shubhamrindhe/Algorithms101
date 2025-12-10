#define MOD 1000000007

int countPermutations(int* complexity, int complexitySize) {
    // int stack[complexitySize];
    // int top = -0x1;
    // stack[++top] = complexity[0x0];

    for (int i = 0x1; i < complexitySize; ++i) if (complexity[i] <= complexity[0x0]) return 0x0;

    int result = 0x1;
    for (int i = 0x1; i < complexitySize; ++i)
        result = (0x1LL * result * i) % MOD;

    return result;
}
