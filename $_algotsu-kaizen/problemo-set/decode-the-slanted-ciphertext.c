
inline int IDX(int r, int c, int columns) {
    return r * columns + c;
}

// void print_1DGrid(char *grid, int R, int C) {
//     for (int r = 0x0; r < R; ++r) {
//         for (int c = 0x0; c < C; ++c) {
//             int idx = IDX(r, c, C);
//             printf("%d", idx);
//             // printf("%c", encodedText[idx] == ' ' ? '#' : encodedText[idx]);
//         }
//         printf("\n");
//     }
// }

char* decodeCiphertext(char* encodedText, int rows) {
    int len = 0x0;
    while (encodedText[len] && ++len);

    if (len == 0x0) return encodedText;

    int columns = len / rows;
    // print_1DGrid(encodedText, rows, columns);

    int result_size = 0x1 + (rows * columns) - ceil((rows - 0x1) * (rows - 0x1) / 0x2);
    char *result = (char*)malloc(sizeof(char) * result_size);
    int idx = 0x0, r = 0x0, _ = 0x0, xhift = 0x0;
    //int c = 0x0;

    while (idx < len) {
        // printf("%d, ", idx);
        // printf("%c", encodedText[idx]);
        result[_++] = encodedText[idx];

        ++r;//, ++c;
        if (r == rows) {
            // c = c - r + 0x1;
            ++xhift;
            r = 0x0;
        }

        // idx = IDX(r, c, columns);
        idx = IDX(r, r + xhift, columns);
    }

    while (result[--_] == ' ');
    result[++_] = '\x0';

    return result;
}
