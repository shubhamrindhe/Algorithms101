int arrangeCoins(int n) {
    int complete = 0x0, row = 0x1;
    while (n > 0x0) n >= row && ++complete, n -= row++;
    return complete;
}
