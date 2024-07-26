/**
 * 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 * https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 */

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} distanceThreshold
 * @return {number}
 */
var findTheCity = function (n, edges, distanceThreshold) {
    let matrix = new Array(n)
    for (var r = 0; r < n; r++) matrix[r] = Array.apply(null, Array(n)).map(Number.prototype.valueOf, Infinity)

    for (const [s, d, w] of edges) {
        matrix[s][d] = w
        matrix[d][s] = w
    }

    for (let i = 0; i < n; ++i) matrix[i][i] = 0

    for (let k = 0; k < n; k++)
        for (let i = 0; i < n; i++)
            for (let j = 0; j < n; j++)
                matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k][j])

    let minProximates = n
    let node = -Infinity

    for (let i = 0; i < n; ++i) {
        const proximateNodes = matrix[i].filter(distance => distance <= distanceThreshold)
        if (proximateNodes.length <= minProximates) {
            minProximates = proximateNodes.length
            node = i
        }
    }

    return node
};

export { findTheCity }

// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
console.log("$#",
    findTheCity(
        4,
        [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]],
        4
    ),
    3
);

// Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
// Output: 0
console.log("$#",
    findTheCity(
        5,
        [[0, 1, 2], [0, 4, 8], [1, 2, 3], [1, 4, 2], [2, 3, 1], [3, 4, 1]],
        2
    ),
    0
);
