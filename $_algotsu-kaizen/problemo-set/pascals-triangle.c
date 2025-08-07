/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result = (int **)malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    int *columnSizes = (int*)malloc(sizeof(int) * numRows);
    *returnColumnSizes = columnSizes;

    for (int _ = 0, row = 1; _ < numRows; ++row, ++_) {
        result[_] = (int*)calloc(sizeof(int), row);
        result[_][0] = 1;
        result[_][row - 1] = 1;

        // printf("\n");
        for (int j = 1; j < row - 1; ++j) {
            // printf(" %d + %d = %d ",
            // result[_ - 1][j - 1],
            // result[_ - 1][j],
            // result[_ - 1][j - 1] + result[_ - 1][j]);
            result[_][j] = result[_ - 1][j - 1] + result[_ - 1][j];
        }

        columnSizes[_] = row;
    }

    return result;
}
