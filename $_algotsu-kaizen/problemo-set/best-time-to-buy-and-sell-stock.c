#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef struct {
    int maxValue;
    int maxProfit;
} Data;

int maxProfit(int* prices, int pricesSize) {
    Data dp[pricesSize];// = (Data*)malloc(sizeof(Data) * pricesSize);

    int index = pricesSize - 0x1;
    dp[index].maxValue = prices[index];
    dp[index].maxProfit = 0x0;

    while (index > 0x0) {
        Data future = dp[index--];
        dp[index].maxValue = MAX(future.maxValue, prices[index]);
        dp[index].maxProfit = MAX(future.maxProfit, future.maxValue - prices[index]);
    }

    return dp[0x0].maxProfit;
}
