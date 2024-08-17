/**
 * 1937. Maximum Number of Points with Cost
 * https://leetcode.com/problems/maximum-number-of-points-with-cost/description/
 */

/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function (points) {
  const R = points.length, C = points[0].length, dp = [...points[0]]

  for (let row = 1; row < R; ++row) {
    let l2r = Array.apply(null, Array(C)).map(Number.prototype.valueOf, 0)
    l2r[0] = dp[0]
    let r2l = Array.apply(null, Array(C)).map(Number.prototype.valueOf, 0)
    r2l[C - 1] = dp[C - 1]
    for (let l = 1; l < C; ++l) l2r[l] = Math.max(l2r[l - 1] - 1, dp[l])
    for (let r = C - 2; r >= 0; --r) r2l[r] = Math.max(r2l[r + 1] - 1, dp[r])
    for (let c = 0; c < C; ++c) dp[c] = points[row][c] + Math.max(l2r[c], r2l[c])
  }

  return Math.max(...dp)
};

// /**
//  * @param {number[][]} books
//  * @param {number} shelfWidth
//  * @return {number}
//  */
// var minHeightShelves = function (
//   books,
//   shelfWidth,
//   idx = 0,
//   dp = new Array(1000)
// ) {
//   if (idx == books.length) return 0;
//   if (dp[idx]) return dp[idx];
//   let availWidth = Number(shelfWidth);
//   let maxHeight = 0;
//   dp[idx] = Infinity;
//   for (let i = idx; i < books.length; ++i) {
//     const [bwidth, bheight] = books[i];
//     if (bwidth > availWidth) break;
//     availWidth -= bwidth;
//     maxHeight = Math.max(maxHeight, bheight);

//     dp[idx] = Math.min(
//       dp[idx],
//       minHeightShelves(books, shelfWidth, i + 1, dp) + maxHeight
//     );
//   }

//   return dp[idx];
// };

export { maxPoints };

// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
// Output: 9
console.log(
  "$#",
  maxPoints([
    [1, 2, 3],
    [1, 5, 1],
    [3, 1, 1],
  ]),
  9
);

// Input: points = [[1,5],[2,3],[4,2]]
// Output: 11
console.log(
  "$#",
  maxPoints([
    [1, 5],
    [2, 3],
    [4, 2],
  ]),
  11
);

// Input: points = [[3],[4],[2],[0]]
// Output: 9
console.log("$#", maxPoints([[3], [4], [2], [0]]), 9);

// Input: points = [[5,2,1,2],[2,1,5,2],[5,5,5,0]]
// Output: 13
console.log(
  "$#",
  maxPoints([
    [5, 2, 1, 2],
    [2, 1, 5, 2],
    [5, 5, 5, 0],
  ]),
  13
);
