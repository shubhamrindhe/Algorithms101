/**
 * 1791. Find Center of Star Graph
 * https://leetcode.com/problems/find-center-of-star-graph/description/
 */

/**
 * @param {number[][]} edges
 * @return {number}
 */
const findCenter = (edges) => {
    const [ edgeOne, [u , v] ] = edges
    if (edgeOne.includes(u)) return u
    return v
};

export { findCenter }

console.log("$#", findCenter([[1, 2], [2, 3], [4, 2]]), 2);
// Input: edges = [[1,2],[2,3],[4,2]]
// Output: 2

console.log("$#", findCenter([[1, 2], [5, 1], [1, 3], [1, 4]]), 1);
// Input: edges = [[1,2],[5,1],[1,3],[1,4]]
// Output: 1
