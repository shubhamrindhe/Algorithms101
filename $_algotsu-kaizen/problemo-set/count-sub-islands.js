/**
 * 1905. Count Sub Islands
 * https://leetcode.com/problems/count-sub-islands/description/
 */

/**
 * @param {number[][]} grid1
 * @param {number[][]} grid2
 * @return {number}
 */
var countSubIslands = function (grid1, grid2) {
    const R = grid1.length, C = grid1[0].length;

    const dfs = (grid, r, c, visitedSet, island = []) => {
        if (
            r < 0 ||
            c < 0 ||
            r >= R ||
            c >= C ||
            grid[r][c] != 1 ||
            visitedSet.has(`${r}.${c}`)
        ) return

        visitedSet.add(`${r}.${c}`)
        island.push([r, c])

        const neighbours = [
            [r + 1, c],
            [r, c + 1],
            [r - 1, c],
            [r, c - 1],
        ]
        neighbours.forEach((neighbour) => dfs(grid, ...neighbour, visitedSet, island))

        return island
    };

    const islands = []
    let visitedHashSet = new Set();
    for (let r = 0; r < R; ++r) {
        for (let c = 0; c < C; ++c) {
            if (grid2[r][c] == 1 && !visitedHashSet.has(`${r}.${c}`)) {
                islands.push(dfs(grid2, r, c, visitedHashSet))
            }
        }
    }

    let count = 0;
    for (const island of islands) {
        let isSubisland = true
        for (const [x, y] of island)
            if (grid1[x][y] == 0) {
                isSubisland = false
                break
            }
        isSubisland && ++count
    }

    return count
};

export { countSubIslands };

// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
console.log(
    "$#",
    countSubIslands(
        [[1, 1, 1, 0, 0], [0, 1, 1, 1, 1], [0, 0, 0, 0, 0], [1, 0, 0, 0, 0], [1, 1, 0, 1, 1]],
        [[1, 1, 1, 0, 0], [0, 0, 1, 1, 1], [0, 1, 0, 0, 0], [1, 0, 1, 1, 0], [0, 1, 0, 1, 0]]
    ),
    3
);

// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// Output: 2
console.log("$#",
    countSubIslands(
        [[1, 0, 1, 0, 1], [1, 1, 1, 1, 1], [0, 0, 0, 0, 0], [1, 1, 1, 1, 1], [1, 0, 1, 0, 1]],
        [[0, 0, 0, 0, 0], [1, 1, 1, 1, 1], [0, 1, 0, 1, 0], [0, 1, 0, 1, 0], [1, 0, 0, 0, 1]]
    ),
    2
);
