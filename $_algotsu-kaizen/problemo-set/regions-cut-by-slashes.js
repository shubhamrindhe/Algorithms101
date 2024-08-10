/**
 * 959. Regions Cut By Slashes
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
 */

/**
 * @param {string[]} grid
 * @return {number}
 */
var regionsBySlashes = function (grid) {
  const n = grid.length, N = n * 3;

  let matrix = new Array(N);
  for (var r = 0; r < N; r++) matrix[r] = Array.apply(null, Array(N)).map(Number.prototype.valueOf, 0);

  for (let [r, row] of grid.entries()) {
    for (let c = 0; c < row.length; ++c) {
      const R = r * 3, C = c * 3;
      switch (row.charAt(c)) {
        case "/":
        matrix[R][C + 2] = matrix[R + 1][C + 1] = matrix[R + 2][C] = -1;
        //   matrix[R][C + 2] = -1;
        //   matrix[R + 1][C + 1] = -1;
        //   matrix[R + 2][C] = -1;
          break;
        case "\\":
        matrix[R][C] = matrix[R + 1][C + 1] = matrix[R + 2][C + 2] = -1;
        //   matrix[R][C] = -1;
        //   matrix[R + 1][C + 1] = -1;
        //   matrix[R + 2][C + 2] = -1;
          break;
      }
    }
  }

  const dfs = (r, c, visitedHashSet) => {
    if (r < 0 || c < 0 || r >= N || c >= N || matrix[r][c] != 0 || visitedHashSet.has(`${r}.${c}`)) return
    visitedHashSet.add(`${r}.${c}`)
    const neighbours = [[r + 1, c], [r, c + 1], [r - 1, c], [r, c - 1]]
    neighbours.forEach(neighbour => dfs(...neighbour, visitedHashSet))
  }

  let visitedHashSet = new Set()
  let count = 0
  for (let r = 0; r < N; ++r) {
    for (let c = 0; c < N; ++c) {
        if (matrix[r][c] == 0 && !visitedHashSet.has(`${r}.${c}`)) {
            dfs(r, c, visitedHashSet)
            ++count
        }
    }
  }

  return count
};

export { regionsBySlashes };

// Input: grid = [" /","/ "]
// Output: 2
console.log("$#", regionsBySlashes([" /", "/ "]), 2);

// Input: grid = [" /","  "]
// Output: 1
console.log("$#", regionsBySlashes([" /", "  "]), 1);

// Input: grid = ["/\\","\\/"]
// Output: 5
console.log("$#", regionsBySlashes(["/\\", "\\/"]), 5);
