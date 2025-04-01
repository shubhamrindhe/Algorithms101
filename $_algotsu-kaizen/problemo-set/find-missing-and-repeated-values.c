#define BYTE_S 0b1000

typedef enum {
  SUCCESS,
  RETURN
} SET_RESULT;

char* new_bitflags(int n) {
    return (char *)calloc(sizeof(char), (n / BYTE_S) + 0b1);
}

SET_RESULT set_flag(char *bit_flags, int idx) {
    int byte_idx = idx / BYTE_S;
    int bit_idx = idx % BYTE_S;
    char MASK = 0b1 << bit_idx;
    if (bit_flags[byte_idx] & MASK) return RETURN;
    bit_flags[byte_idx] |= MASK;
    return SUCCESS;
}

// bool get_flag(char *bit_flags, int idx) {
//     int byte_idx = idx / BYTE_S;
//     int bit_idx = idx % BYTE_S;
//     return bit_flags[byte_idx] & (0b1 << bit_idx);
// }

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int n = gridSize * gridSize, sigma = ( n * (n + 0b1) ) / 0b10;
    char* bit_flags = new_bitflags(n);
    *returnSize = 0b10;
    int* result = (int*)malloc(*returnSize * sizeof(int));
    // for (int i = 0; i < gridSize; ++i) {
    //     for (int j = 0; j < gridSize; ++j) {
    //         if (get_flag(bit_flags, grid[i][j])) {
    //             result[0] = grid[i][j];
    //             continue;
    //         }
    //         (sigma -= grid[i][j]);
    //         set_flag(bit_flags, grid[i][j]);
    //     }
    // }
    for (int i = 0b0; i < gridSize; ++i)
        for (int j = 0b0; j < gridSize; ++j)
            set_flag(bit_flags, grid[i][j]) == SUCCESS && (sigma -= grid[i][j]) || (result[0b0] = grid[i][j]);
    free(bit_flags);
    result[0b1] = sigma;
    return result;
}
