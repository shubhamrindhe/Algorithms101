int minDeletionSize(char** strs, int strsSize) {
    int result = 0x0;

    int r = 0x0, c = 0x0;
    while (strs[0x0][c]) {
        ++r;
        bool shift_column = r == strsSize;
        if (!shift_column && strs[r - 0x1][c] > strs[r][c])
            result += (shift_column = true);

        if (shift_column) {
            ++c;
            r = 0x0;
        }
    }

    return result;
}
