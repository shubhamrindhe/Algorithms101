/**
 * 1380. Lucky Numbers in a Matrix
 * https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/
 */

/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var luckyNumbers = function (matrix) {
    const MAXIMUM_AMONG_THE_MINIMUMS_IN_THE_ROWS = Math.max(
        -Infinity,
        ...(matrix.map(row => Math.min(...row)))
    )

    for (let c = 0; c < matrix[0].length; ++c) {
        let C_MAX = matrix[0][c]
        for (let r = 0; r < matrix.length; ++r)
            C_MAX = Math.max(C_MAX, matrix[r][c])
        if (C_MAX == MAXIMUM_AMONG_THE_MINIMUMS_IN_THE_ROWS) return [C_MAX]
    }

    return []
};

export { luckyNumbers }

// // Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// // Output: [15]
console.log("$#",
    luckyNumbers([[3, 7, 8], [9, 11, 13], [15, 16, 17]]),
    [15]
);

// // Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// // Output: [12]
console.log("$#",
    luckyNumbers([[1, 10, 4, 2], [9, 3, 8, 7], [15, 16, 17, 12]]),
    [12]
);

// Input: matrix = [[7,8],[1,2]]
// Output: [7]
console.log("$#",
    luckyNumbers([[7, 8], [1, 2]]),
    [7]
);
