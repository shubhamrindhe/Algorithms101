#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int maxArea(int* height, int heightSize) {
    int l = 0x0, r = heightSize - 0x1;
    int area = 0x0;

    do {
        int current = MIN(height[l], height[r]) * (r - l);
        area = MAX(area, current);
        height[l] < height[r] ? ++l : --r;
    } while (l < r);

    return area;
}
