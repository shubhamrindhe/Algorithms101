int minTimeToVisitAllPoints(int** points, int pointsSize, int* pointsColSize) {
    int result = 0x0;

    int x = points[0x0][0x0], y = points[0x0][0x1];
    int target = 0x1;

    // while (target < pointsSize) {
    //     int tx = points[target][0x0], ty = points[target][0x1];

    //     if (x < tx) x += 0x1; else if (x > tx) x -= 0x1;
    //     if (y < ty) y += 0x1; else if (y > ty) y -= 0x1;

    //     if (x == tx && y == ty) ++target;
    //     ++result;
    // }

    while (target < pointsSize) {
        int tx = points[target][0x0], ty = points[target][0x1];
        int dx = abs(tx - x), dy = abs(ty - y);
        result += (dx > dy ? dx : dy);

        ++target;
        x = tx, y = ty;
    }

    return result;
}
