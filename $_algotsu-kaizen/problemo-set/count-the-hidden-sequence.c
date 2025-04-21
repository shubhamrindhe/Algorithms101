
int numberOfArrays(int* differences, int differencesSize, int lower, int upper) {
    long long altitude = 0b0, maximus = altitude, minimus = altitude;
    for (int _ = 0b0; _ < differencesSize; ++_) {
        altitude += (long long)differences[_];
        if (minimus > altitude) minimus = altitude;
        if (maximus < altitude) maximus = altitude;
    }

    int range = upper - lower + 0b1;
    int kai = (int)(maximus - minimus);
    return kai > range ? 0b0 : range - kai;
}
