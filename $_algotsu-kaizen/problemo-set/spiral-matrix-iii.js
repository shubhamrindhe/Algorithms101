/**
 * 885. Spiral Matrix III
 * https://leetcode.com/problems/spiral-matrix-iii/description/
 */

/**
 * @param {number} rows
 * @param {number} cols
 * @param {number} rStart
 * @param {number} cStart
 * @return {number[][]}
 */
var spiralMatrixIII = function (rows, cols, rStart, cStart) {
  const output = [];
  const dir = [
      [0, 1],
      [1, 0],
      [0, -1],
      [-1, 0],
    ],
    size = rows * cols;

  let curDir = 0,
    steps = 1,
    r = rStart,
    c = cStart;

  while (output.length < size) {
    for (let i = 0; i < 2; ++i) {
      for (let j = 0; j < steps; ++j) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
          output.push([r, c]);
        }
        r += dir[curDir][0];
        c += dir[curDir][1];
      }
      curDir = ++curDir % 4;
    }
    ++steps;
  }

  return output;
};

export { spiralMatrixIII };

// Input: rows = 1, cols = 4, rStart = 0, cStart = 0
// Output: [[0,0],[0,1],[0,2],[0,3]]
console.log("$#", spiralMatrixIII(1, 4, 0, 0), [
  [0, 0],
  [0, 1],
  [0, 2],
  [0, 3],
]);

// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
console.log(
  "$#",
  spiralMatrixIII(5, 6, 1, 4).toString(),
  [
    [1, 4],
    [1, 5],
    [2, 5],
    [2, 4],
    [2, 3],
    [1, 3],
    [0, 3],
    [0, 4],
    [0, 5],
    [3, 5],
    [3, 4],
    [3, 3],
    [3, 2],
    [2, 2],
    [1, 2],
    [0, 2],
    [4, 5],
    [4, 4],
    [4, 3],
    [4, 2],
    [4, 1],
    [3, 1],
    [2, 1],
    [1, 1],
    [0, 1],
    [4, 0],
    [3, 0],
    [2, 0],
    [1, 0],
    [0, 0],
  ].toString()
);
