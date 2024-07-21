/**
 * 2392. Build a Matrix With Conditions
 * https://leetcode.com/problems/build-a-matrix-with-conditions/description/
 */

/**
 * @param {number} k
 * @param {number[][]} rowConditions
 * @param {number[][]} colConditions
 * @return {number[][]}
 */
var buildMatrix = function (k, rowConditions, colConditions) {
    const dfs = (node, setMap, order, visited, path) => {
        if (path.has(node)) return false
        if (visited.has(node)) return true

        visited.add(node)
        path.add(node)
        for (const next of setMap.get(node)) {
            if (dfs(next, setMap, order, visited, path)) continue
            return false
        }

        path.delete(node)
        order.push(node)

        return true
    }

    const topologicalSort = (edges) => {
        const setMap = new Map()
        for (let key = 1; key <= k; ++key) setMap.set(key, [])
        for (const [node, next] of edges) setMap.get(node).push(next)

        let order = []

        let visited = new Set(), path = new Set()
        for (let key = 1; key <= k; ++key) {
            if (dfs(key, setMap, order, visited, path)) continue
            return []
        }

        return order.reverse()
    }

    let matrix = new Array(k)
    for (var r = 0; r < k; r++) matrix[r] = Array.apply(null, Array(k)).map(Number.prototype.valueOf, 0)

    let row_order = topologicalSort(rowConditions)
    let col_order = topologicalSort(colConditions)

    if (row_order.length == 0 || col_order.length == 0) return []

    const row_idx_map = new Map(row_order.map((e, i) => [e, i]))
    const col_idx_map = new Map(col_order.map((e, i) => [e, i]))
    for (let n = 1; n <= k; ++n) matrix[row_idx_map.get(n)][col_idx_map.get(n)] = n

    return matrix
};

export { buildMatrix }

// Input: k = 3, rowConditions = [[1, 2], [3, 2]], colConditions = [[2, 1], [3, 2]]
// Output: [
//     [3, 0, 0],
//     [0, 0, 1],
//     [0, 2, 0]
// ]
console.log("$#",
    buildMatrix(
        3, [[1, 2], [3, 2]], [[2, 1], [3, 2]]
    ).toString(),
    [
        [3, 0, 0],
        [0, 0, 1],
        [0, 2, 0]
    ].toString()
);

// Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
// Output: []
console.log("$#",
    buildMatrix(
        3, [[1, 2], [2, 3], [3, 1], [2, 3]], [[2, 1]]
    ).toString(),
    [].toString()
);
