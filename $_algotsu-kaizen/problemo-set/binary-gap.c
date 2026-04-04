int binaryGap(int n) {
    int result = 0x0;
    int _ = 0x0, last = -0x1, mask;

    while ((mask = 0x1 << _) < n) {
        if (n & mask) {
            if (last >= 0x0 && result < (_ - last)) result = _ - last;
            last = _;
        }
        ++_;
    }

    return result;
}
