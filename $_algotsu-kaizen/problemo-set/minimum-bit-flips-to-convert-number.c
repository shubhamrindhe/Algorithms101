
int minBitFlips(int start, int goal) {
    unsigned int bit = 0b1;
    int kai_bits = 0b0, max = start > goal ? start : goal;

    while (bit <= max) {
        if ((goal & bit) ^ (start & bit))
            kai_bits++;
        bit = bit << 0b1;
    }

    return kai_bits;
}
