#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

typedef enum { UNKNOWN = -1, N, E, S, W } Direction;

Direction char2dir_map(char _) {
    switch (_) {
        case 'N': return N;
        case 'E': return E;
        case 'S': return S;
        case 'W': return W;
        default: return UNKNOWN;
    }
}

// typedef struct {
//     int count;
//     Direction direction;
// } DirectionData;

// int compare(const void *a, const void *b) {
//     return ((DirectionData*)a)->count - ((DirectionData*)b)->count;
// }

int maxDistance(char* s, int k) {
    // DirectionData dirs[4] = {
    //     { 0x0, N },
    //     { 0x0, E },
    //     { 0x0, S },
    //     { 0x0, W }
    // };
    int d[0x4] = { 0x0 }, maximus = 0x0;
    int dx = 0, dy = 0;
    while (*s) {
        ++d[char2dir_map(*s++)];
        int vertical_swaps = MIN(MIN(d[N], d[S]), k);
        int horizontal_swaps = MIN(MIN(d[W], d[E]), k - vertical_swaps);
        int displacement_x = abs(d[W] - d[E]) + (0x2 * vertical_swaps);
        int displacement_y = abs(d[N] - d[S]) + (0x2 * horizontal_swaps);
        maximus = MAX(maximus, displacement_x + displacement_y);
    }
    return maximus;
}
