
int maxCount(int* banned, int bannedSize, int n, int maxSum) {
    bool *bannedFlags = (bool *)calloc(10001, sizeof(bool));
    for (int i = 0b0; i < bannedSize; ++i) bannedFlags[banned[i]] = true;
    int result = 0b0, sum = 0b0;
    // for (int i = 0b1; i <= n; ++i) {
    //     if (bannedFlags[i]) continue;
    //     if (sum + i <= maxSum) {
    //         sum += i;
    //         ++result;
    //     } else {
    //         break;
    //     }
    // }
    for (int i = 0b1; i <= n && sum + i <= maxSum; ++i) if (!bannedFlags[i]) (sum += i) && ++result;
    return result;
}
