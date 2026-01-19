static inline int maximus(int one, int two) {
    return one > two ? one : two;
}

static inline int minimus(int one, int two) {
    return one < two ? one : two;
}

typedef struct Rectangle {
    // int width, height;
    int minX, maxX;
    int minY, maxY;
} Rectangle;

Rectangle new_rect(int *bottomLeft, int *topRight) {
    // int width = topRight[0] - bottomLeft[0];
    // int height = topRight[1] - bottomLeft[1];
    return (Rectangle) {
        // .width = width,
        // .height = height,
        .minX = bottomLeft[0],
        .maxX = topRight[0],
        .minY = bottomLeft[1],
        .maxY = topRight[1]
    };
}

// void intersection(Rectangle *one, Rectangle *two, int *max_dimention) {
//     int minX = maximus(one->minX, two->minX);
//     int maxX = minimus(one->maxX, two->maxX);
//     int minY = maximus(one->minY, two->minY);
//     int maxY = minimus(one->maxY, two->maxY);

//     if (minX >= maxX || minY >= maxY) {
//         // *max_dimention = 0x0;
//     } else {
//         *max_dimention = maximus(*max_dimention, minimus(maxX - minX, maxY - minY));
//     }
// }

void intersection(Rectangle *one, Rectangle *two, int *max_dimention) {
    int minX = maximus(one->minX, two->minX);
    int maxX = minimus(one->maxX, two->maxX);
    int minY = maximus(one->minY, two->minY);
    int maxY = minimus(one->maxY, two->maxY);

    if (minX >= maxX || minY >= maxY) {
        // *max_dimention = 0x0;
    } else {
        *max_dimention = maximus(*max_dimention, minimus(maxX - minX, maxY - minY));
    }
}

long long largestSquareArea(int** bottomLeft, int bottomLeftSize, int* bottomLeftColSize, int** topRight, int topRightSize, int* topRightColSize) {
    int N = bottomLeftSize;
    Rectangle cache[N];
    int cache_idx = -0x1;

    int max_dimention = 0x0;

    for (int i = 0x0; i < N; ++i) {
        if (cache_idx < i) cache[(cache_idx = i)] = new_rect(bottomLeft[i], topRight[i]);
        for (int j = i + 0x1; j < N; ++j) {
            if (cache_idx < j) cache[(cache_idx = j)] = new_rect(bottomLeft[j], topRight[j]);
            intersection(cache + i, cache + j, &max_dimention);
        }
    }

    return 1LL * max_dimention * max_dimention;
}
