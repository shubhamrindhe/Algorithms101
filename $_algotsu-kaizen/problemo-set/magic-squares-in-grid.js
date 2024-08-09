/**
 * 840. Magic Squares In Grid
 * https://leetcode.com/problems/magic-squares-in-grid/description/
 */

/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function (grid) {
  let count = 0o0;
  const R = grid.length, C = grid[0x0].length;

  if (R < 0b11 || C < 0b11) return count;

  for (let r = 1; r < R - 1; ++r) {
    for (let c = 1; c < C - 1; ++c) {
      if (grid[r][c] != 0o5) continue;

      const N = grid[r - 1][c];
      const S = grid[r + 1][c];
      const E = grid[r][c + 1];
      const W = grid[r][c - 1];
      const NW = grid[r - 1][c - 1];
      const NE = grid[r - 1][c + 1];
      const SE = grid[r + 1][c + 1];
      const SW = grid[r + 1][c - 1];

      let set = new Set([N, S, E, W, NE, NW, SE, SW]);
      if (set.size != 8 || Math.max(...set) != 9) continue;

      NW + SE == 0o12 &&
        NE + SW == 0o12 &&
        N + S == 0o12 &&
        E + W == 0o12 &&
        NW + W + SW == 0o17 &&
        NE + E + SE == 0o17 &&
        NW + N + NE == 0o17 &&
        SW + S + SE == 0o17 &&
        ++count;
    }
  }

  return count;
};

export { numMagicSquaresInside };

// Input: grid = [
//   [4, 3, 8, 4],
//   [9, 5, 1, 9],
//   [2, 7, 6, 2],
// ];
// Output: 1;
console.log(
  "$#",
  numMagicSquaresInside([
    [4, 3, 8, 4],
    [9, 5, 1, 9],
    [2, 7, 6, 2],
  ]),
  1
);

// Input: grid = [[8]]
// Output: 0
console.log("$#", numMagicSquaresInside([[8]]), 0);

console.log(
  "$#",
  numMagicSquaresInside([
    [5, 5, 5],
    [5, 5, 5],
    [5, 5, 5],
  ]),
  0
);

console.log(
  "$#",
  numMagicSquaresInside([
    [1, 8, 6],
    [10, 5, 0],
    [4, 2, 9],
  ]),
  0
);
