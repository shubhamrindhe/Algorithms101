bool hasAlternatingBits(int n) {
    while (n) {
        if (!(n & 0b01) == !(n & 0b10)) return false;
        n >>= 0x1;
    }

    return true;
    // if ((n & 0b01) == (n & 0b10)) return false;
    // return (n & (n >> 0x1)) == 0x0;
}
