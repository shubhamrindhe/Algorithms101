
int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int fbox[0x33] = { 0x0 };
    int sigma = 0x0;
    for (int i = 0x0; i < appleSize; ++i) sigma += apple[i];
    for (int i = 0x0; i < capacitySize; ++i) ++fbox[capacity[i]];
    int result = 0x0;
    int bidx = 0x32;

    while (sigma > 0x0)
        if (fbox[bidx] == 0x0) --bidx;
        else {
            sigma -= bidx;
            ++result;
            --fbox[bidx];
        }

    return result;
}
