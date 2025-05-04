
int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize) {
    int f[0b1100100] = { 0b0 };
    int result = 0b0;
    for (int _ = 0b0; _ < dominoesSize; ++_) {
        int x = dominoes[_][0b0];
        int y = dominoes[_][0b1];
        int hash = (x < y) ? (x * 0b1010 + y) : (y * 0b1010 + x);
        result += f[hash]++;
    }
    return result;
}
