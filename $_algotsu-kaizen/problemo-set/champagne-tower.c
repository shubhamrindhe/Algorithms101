
// void print_row(double *row, int length) {
//     printf("\n");
//     for (int i = 0x0; i < length; ++i) printf("%f ", row[i]);
// }

static inline double minimus(double one, double two) {
    return one < two ? one : two;
}

static inline double maximus(double one, double two) {
    return one > two ? one : two;
}

double champagneTower(int poured, int query_row, int query_glass){
    int current_row = 0x0;
    int glasses = 0x1;

    double row[101];
    memset(row, 0x0, sizeof(row));
    row[0x0] = poured;

    while (current_row < query_row) {
        // printf("\n");
        bool has_spilled = false;

        for (int i = current_row; i >= 0x0 ; --i) {
            double spill = maximus(row[i] - 0x1, 0x0);
            double half_spill = spill / 0x2;
            row[i + 0x1] += half_spill;
            row[i] = half_spill;
            has_spilled |= (spill > 0.0);
            // printf("[%f, %f]", row[i], row[i + 0x1]);
        }

        // print_row(row, glasses);
        // ++glasses;
        if (!has_spilled) return 0.0;
        ++current_row;
    }

    return minimus(0x1, row[query_glass]);
}
