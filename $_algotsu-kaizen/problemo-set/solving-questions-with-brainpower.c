
long long _(int** questions, int questionsSize, long long* dp, int idx) {
    if (idx >= questionsSize) return 0LL;
    int* question = questions[idx];
    int points = question[0], brainpower = question[1];
    if (dp[idx] > 0) return dp[idx];
    long long solvedPoint = points + _(questions, questionsSize, dp, idx + brainpower + 1);
    long long skippedPoint = _(questions, questionsSize, dp, idx + 1);
    dp[idx] = solvedPoint > skippedPoint ? solvedPoint : skippedPoint;
    return dp[idx];
}

long long mostPoints(int** questions, int questionsSize, int* questionsColSize) {
    long long *dp = (long long *)calloc(sizeof(long long), questionsSize);
    _(questions, questionsSize, dp, 0);
    long long maximus = 0LL;
    for (int i = 0; i < questionsSize; ++i)
        if (maximus < dp[i]) maximus = dp[i];
        // printf(" %lld ", dp[i]);
    return maximus;
}
