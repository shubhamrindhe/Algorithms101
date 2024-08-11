/**
 * 959. Regions Cut By Slashes
 * https://leetcode.com/problems/regions-cut-by-slashes/description/
 */

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minDays = function (grid) {
  const R = grid.length, C = grid[0].length;

  const dfs = (r, c, visitedSet) => {
    if (
      r < 0 ||
      c < 0 ||
      r >= R ||
      c >= C ||
      grid[r][c] != 1 ||
      visitedSet.has(`${r}.${c}`)
    )
      return;
      visitedSet.add(`${r}.${c}`);
    const neighbours = [
      [r + 1, c],
      [r, c + 1],
      [r - 1, c],
      [r, c - 1],
    ];
    neighbours.forEach((neighbour) => dfs(...neighbour, visitedSet));
  };

  const islandsCount = () => {
    let count = 0;
    let visitedHashSet = new Set();
    for (let r = 0; r < R; ++r) {
      for (let c = 0; c < C; ++c) {
        if (grid[r][c] == 1 && !visitedHashSet.has(`${r}.${c}`)) {
          dfs(r, c, visitedHashSet);
          ++count;
        }
      }
    }
    return count;
  };

  if (islandsCount() != 1) return 0;

  for (let r = 0; r < R; ++r) {
    for (let c = 0; c < C; ++c) {
      if (grid[r][c] == 1) {
        grid[r][c] = 0
        let count = islandsCount()
        grid[r][c] = 1
        if (count != 1) return 1
      }
    }
  }

  return 2;
};

export { minDays };

// Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 2
console.log(
  "$#",
  minDays([
    [0, 1, 1, 0],
    [0, 1, 1, 0],
    [0, 0, 0, 0],
  ]),
  2
);

// Input: grid = [[1,1]]
// Output: 2
console.log("$#", minDays([[1, 1]]), 2);
