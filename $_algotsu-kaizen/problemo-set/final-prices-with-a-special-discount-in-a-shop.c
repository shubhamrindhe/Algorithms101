/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int* result = (int *)malloc(sizeof(int) * pricesSize);
    *returnSize = pricesSize;
    int* stack = (int *)calloc(sizeof(int), pricesSize);
    int top = -1;

    for (int i = pricesSize - 1; i >= 0; --i) {
        while (top > -1 && stack[top] > prices[i] && top--);
        result[i] = prices[i] - (top > -1 ? stack[top] : 0);
        stack[++top] = prices[i];
    }

    free(stack);

    // for (int i = 0; i < pricesSize; ++i) {
    //     int discount = 0;
    //     for (int j = i + 1; j < pricesSize; ++j) {
    //         if (prices[j] <= prices[i]) {
    //             discount = prices[j];
    //             break;
    //         }
    //     }
    //     result[i] = prices[i] - discount;
    // }

    return result;
}
