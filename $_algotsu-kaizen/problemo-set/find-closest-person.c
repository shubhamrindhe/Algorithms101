int findClosest(int x, int y, int z) {
    int xz = abs(z - x), yz = abs(z - y);
    return xz == yz ? 0x0 : 0x1 + (xz > yz);
}
