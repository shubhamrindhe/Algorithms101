int countPrimeSetBits(int left, int right) {
    int result = 0x0, ones;
    while (left <= right && (ones = __builtin_popcount(left++)))
        (
            ones == 0x02 ||
            ones == 0x03 ||
            ones == 0x05 ||
            ones == 0x07 ||
            ones == 0x0B ||
            ones == 0x0D ||
            ones == 0x11 ||
            ones == 0x13
        ) && ++result;
    return result;
}
