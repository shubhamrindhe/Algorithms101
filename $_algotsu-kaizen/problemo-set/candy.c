#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int candy(int* ratings, int ratingsSize) {
    // int result = ratingsSize;
    // for (int _ = 0; _ < ratingsSize - 1; ++_) if (ratings[_] < ratings[_ + 1]) ++result;
    // for (int _ = ratingsSize - 1; _ > 0; --_) if (ratings[_] < ratings[_ - 1]) ++result;
    // return result;

    int *candies = (int *)malloc(sizeof(int) * ratingsSize);
    for (int _ = 0; _ < ratingsSize; ++_) candies[_] = 0b1;

    for (int _ = 0; _ < ratingsSize - 1; ++_)
        if (ratings[_ + 1] > ratings[_]) candies[_ + 1] = candies[_] + 1;
    for (int _ = ratingsSize - 1; _ > 0; --_)
        if (ratings[_ - 1] > ratings[_]) candies[_ - 1] = MAX(candies[_ - 1], candies[_] + 1);

    int result = 0b0;
    for (int _ = 0b0; _ < ratingsSize; ++_) result += candies[_];
    free(candies);

    return result;
}
