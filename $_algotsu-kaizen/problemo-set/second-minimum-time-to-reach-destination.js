/**
 * 2976. Minimum Cost to Convert String I
 * https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/
 */

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} time
 * @param {number} change
 * @return {number}
 */
var secondMinimum = function (n, edges, time, change) {
    const adjacencyLists = [];
    const distances = [];
    const queue = [];

    for (let i = 1; i <= n; i++) adjacencyLists[i] = []
    edges.forEach(([u, v]) => {
        adjacencyLists[u].push(v)
        adjacencyLists[v].push(u)
    })

    for (let i = 1; i <= n; i++) distances[i] = [Number.MAX_VALUE, Number.MAX_VALUE]
    distances[1][0] = 0
    queue.push([1, 0])

    while (queue.length > 0) {
        const [currentNode, currentDistance] = queue.shift();

        adjacencyLists[currentNode].forEach(neighbor => {
            if (currentDistance + 1 < distances[neighbor][0]) {
                distances[neighbor][0] = currentDistance + 1
                queue.push([neighbor, currentDistance + 1])
            }
            else if (distances[neighbor][0] < currentDistance + 1 && currentDistance + 1 < distances[neighbor][1]) {
                distances[neighbor][1] = currentDistance + 1
                queue.push([neighbor, currentDistance + 1])
            }
        })
    }

    let totalTime = 0;
    for (let i = 0; i < distances[n][1]; i++) {
        totalTime += time
        if (i < distances[n][1] - 1 && totalTime % (2 * change) >= change)
            totalTime += 2 * change - (totalTime % change) - change
    }

    return totalTime
};

export { secondMinimum }

// Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
// Output: 13
console.log("$#",
    secondMinimum(
        5, [[1, 2], [1, 3], [1, 4], [3, 4], [4, 5]], 3, 5
    ),
    13
);

// Input: n = 2, edges = [[1,2]], time = 3, change = 2
// Output: 11
console.log("$#",
    secondMinimum(
        2, [[1,2]], 3, 2
    ),
    11
);
