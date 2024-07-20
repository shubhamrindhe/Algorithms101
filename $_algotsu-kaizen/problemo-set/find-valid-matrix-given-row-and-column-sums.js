/**
 * 1380. Lucky Numbers in a Matrix
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
 */

/**
 * @param {number[]} rowSum
 * @param {number[]} colSum
 * @return {number[][]}
 */
var restoreMatrix = function (rowSum, colSum) {
    // const randomInt = (a, b) => a + Math.round(Math.random() * (b - a))
    // console.log(randomInt(10, 20));

    let matrix = new Array(rowSum.length)
    for (var r = 0; r < matrix.length; r++)
        matrix[r] = Array.apply(null, Array(colSum.length)).map(Number.prototype.valueOf, 0)

    let row = 0, column = 0
    const column_sum = [...colSum], row_sum = [...rowSum]
    while (row < row_sum.length && column < column_sum.length) {
        matrix[row][column] = Math.min(row_sum[row], column_sum[column])
        row_sum[row] = row_sum[row] - matrix[row][column]
        column_sum[column] = column_sum[column] - matrix[row][column]
        row_sum[row] == 0 ? row++ : column++
    }

    return matrix
};

export { restoreMatrix }

// Input: rowSum = [3,8], colSum = [4,7]
// Output: [[3,0],
//          [1,7]]
console.log("$#",
    restoreMatrix(
        [3, 8], [4, 7]
    ),
    [
        [3, 0],
        [1, 7]
    ]
);

// Input: rowSum = [5,7,10], colSum = [8,6,8]
// Output: [[0,5,0],
//          [6,1,0],
//          [2,0,8]]
console.log("$#",
    restoreMatrix(
        [5, 7, 10], [8, 6, 8]
    ),
    [
        [0, 5, 0],
        [6, 1, 0],
        [2, 0, 8]
    ]
);
