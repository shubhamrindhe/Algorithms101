double area_below(int** squares, int squaresSize, double y) {
    double area = 0.0;

    for (int i = 0; i < squaresSize; ++i) {
        int *square = squares[i];
        double y_min = (double)square[1];
        if (y_min >= y) continue;

        double size = (double)square[2];
        double y_max = y_min + size;

        if (y_max <= y) {
            area += size * size;
        } else {
            double kai = y - y_min;
            area += kai * size;
        }
    }

    return area;
}


double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    long long min_y = INT_MAX, max_y = INT_MIN;
    long long total = 0x0LL;

    for (int i = 0; i < squaresSize; ++i) {
        long long s = (long long)squares[i][2];
        total += s * s;

        if (min_y > squares[i][1]) min_y = squares[i][1];
        if (max_y < (squares[i][1] + squares[i][2])) max_y = (squares[i][1] + squares[i][2]);
    }

    double target = ((double)total) / 2.0;
    double l = (double)min_y, h = (double)max_y;

    while ((h - l) > 1e-5) {
        double m = l + (h - l) / 2.0;
        if (area_below(squares, squaresSize, m) < target)
            l = m;
        else
            h = m;
    }

    return h;
}
