int smallestNumber(int n) {
    int result = 0x1;
    while (result <= n) result <<= '\x01';
    return --result;
}
