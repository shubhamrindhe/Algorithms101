#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef enum { X, Y } AXIS;
typedef enum { MIN, MAX } EXTREMA;

int countCoveredBuildings(int n, int** buildings, int buildingsSize, int* buildingsColSize) {
    int x_extrema[n + 0x1][0x2];
    int y_extrema[n + 0x1][0x2];
    memset(x_extrema, 0x0, sizeof(x_extrema));
    memset(y_extrema, 0x0, sizeof(y_extrema));

    for (int i = 0; i <= n; ++i) {
        x_extrema[i][MIN] = n + 1;
        y_extrema[i][MIN] = n + 1;
    }

    int result = 0x0;

    for (int i = 0x0; i < buildingsSize; ++i) {
        int x = buildings[i][X], y = buildings[i][Y];
        x_extrema[x][MIN] = MIN(x_extrema[x][MIN], y);
        x_extrema[x][MAX] = MAX(x_extrema[x][MAX], y);
        y_extrema[y][MIN] = MIN(y_extrema[y][MIN], x);
        y_extrema[y][MAX] = MAX(y_extrema[y][MAX], x);
    }

    for (int i = 0x0; i < buildingsSize; ++i) {
        int x = buildings[i][X], y = buildings[i][Y];
        (x_extrema[x][MIN] < y) &&
        (x_extrema[x][MAX] > y) &&
        (y_extrema[y][MIN] < x) &&
        (y_extrema[y][MAX] > x) &&
        ++result;
    }

    return result;
}
