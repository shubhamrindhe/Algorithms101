/**
 * 1905. Count Sub Islands
 * https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/
 */

/**
 * @param {number[][]} stones
 * @return {number}
 */
var removeStones = function (stones) {
    const row = new Map()
    const col = new Map()

    for (const [r, c] of stones) {
        if (!row.has(r)) row.set(r, [])
        if (!col.has(c)) col.set(c, [])
        row.get(r).push(c)
        col.get(c).push(r)
    }

    // let count = 0b0
    const visitedHashSet = new Set()

    const dfs = (r, c) => {
        if (visitedHashSet.has(`${r}.${c}`)) return
        visitedHashSet.add(`${r}.${c}`)
        // ++count
        const row_adj = row.get(r)
        row_adj.forEach(_ => dfs(r, _))
        const col_adj = col.get(c)
        col_adj.forEach(_ => dfs(_, c))
    }

    let trailingStones = 0b0
    for (const [r, c] of stones) {
        if (visitedHashSet.has(`${r}.${c}`)) continue
        dfs(r, c)
        trailingStones++
    }

    return stones.length - trailingStones
};

export { removeStones };

// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
console.log(
    "$#",
    removeStones(
        [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
    ),
    5
);

// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
console.log("$#",
    removeStones(
        [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]
    ),
    3
);

// [[0,0],[0,1],[1,0],[1,1],[2,1],[2,2],[3,2],[3,3],[3,4],[4,3],[4,4]]
console.log("$#",
    removeStones(
        [[0,0],[0,1],[1,0],[1,1],[2,1],[2,2],[3,2],[3,3],[3,4],[4,3],[4,4]]
    ),
    10
);
