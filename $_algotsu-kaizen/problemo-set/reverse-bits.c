
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0b0U;
    uint32_t mask = 0b1U << 0b11111, idx = 0b0U;
    while (mask) {
        if (n & mask) result |= 0b1U << idx;
        mask >>= 0b1U;
        ++idx;
    }
    return result;
}
