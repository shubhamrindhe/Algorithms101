/**
 * 2699. Modify Graph Edge Weights
 * https://leetcode.com/problems/modify-graph-edge-weights/description/
 */


/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @param {number} target
 * @return {number[][]}
 */
var modifiedGraphEdges = function (n, edges, source, destination, target) {
    // let matrix = new Array(n)
    // for (var r = 0; r < n; r++) matrix[r] = Array.apply(null, Array(n)).map(Number.prototype.valueOf, Infinity)
    // for (const [s, d, w] of edges) matrix[s][d] = matrix[d][s] = w
    // for (let _ = 0; _ < n; ++_) matrix[_][_] = 0

    // for (let k = 0; k < n; k++)
    //     for (let i = 0; i < n; i++)
    //         for (let j = 0; j < n; j++)
    //             matrix[i][j] = Math.min(matrix[i][j], matrix[i][k] + matrix[k][j])

    // for (const row of matrix) console.log(row.toString())

    let adjList = new Map()
    for (const [s, d, w] of edges) {
        if (!adjList.has(s)) adjList.set(s, [])
        if (!adjList.has(d)) adjList.set(d, [])
        adjList.get(s).push([w, d])
        adjList.get(d).push([w, s])
    }

    // class HeapUH {
    //     constructor() {
    //     }
    //     dequeue() {
    //     }
    //     enqueue() {
    //     }
    // }

    const dijkstras = (src) => {
        let pq = []
        let dist = new Array(n).fill(Infinity)
        pq.push([0, src])
        dist[src] = 0

        while (pq.length > 0) {
            let u = pq[0][1]
            pq.shift()

            for(let i = 0; i < adjList.get(u).length; i++){
                const ul = adjList.get(u)
                let v = ul[i][1]
                let weight = ul[i][0]
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight
                    pq.push([dist[v], v])
                    pq.sort((a, b) => {
                        if(a[0] == b[0]) return a[1] - b[1]
                        return a[0] - b[0]
                    })
                }
            }
        }

        return dist
    }

    console.log(dijkstras(source)[destination])

    // let minProximates = n
    // let node = -Infinity

    // for (let i = 0; i < n; ++i) {
    //     const proximateNodes = matrix[i].filter(distance => distance <= distanceThreshold)
    //     if (proximateNodes.length <= minProximates) {
    //         minProximates = proximateNodes.length
    //         node = i
    //     }
    // }

    // return node
};


// /**
//  * @param {number[][]} stones
//  * @return {number}
//  */
// var removeStones = function (stones) {
//     const row = new Map()
//     const col = new Map()

//     for (const [r, c] of stones) {
//         if (!row.has(r)) row.set(r, [])
//         if (!col.has(c)) col.set(c, [])
//         row.get(r).push(c)
//         col.get(c).push(r)
//     }

//     // let count = 0b0
//     const visitedHashSet = new Set()

//     const dfs = (r, c) => {
//         if (visitedHashSet.has(`${r}.${c}`)) return
//         visitedHashSet.add(`${r}.${c}`)
//         // ++count
//         const row_adj = row.get(r)
//         row_adj.forEach(_ => dfs(r, _))
//         const col_adj = col.get(c)
//         col_adj.forEach(_ => dfs(_, c))
//     }

//     let trailingStones = 0b0
//     for (const [r, c] of stones) {
//         if (visitedHashSet.has(`${r}.${c}`)) continue
//         dfs(r, c)
//         trailingStones++
//     }

//     return stones.length - trailingStones
// };

export { modifiedGraphEdges };

// Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
// Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
console.log(
    "$#",
    modifiedGraphEdges(
        5,
        [[4, 1, -1], [2, 0, -1], [0, 3, -1], [4, 3, -1]],
        0,
        1,
        5
    ),
    [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
)

// Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
// Output: []
console.log("$#",
    modifiedGraphEdges(
        3,
        [[0, 1, -1], [0, 2, 5]],
        0,
        2,
        6
    ),
    []
)

// Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
// Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
console.log("$#",
    modifiedGraphEdges(
        4,
        [[1, 0, 4], [1, 2, 3], [2, 3, 5], [0, 3, -1]],
        0,
        2,
        6
    ),
    [[1, 0, 4], [1, 2, 3], [2, 3, 5], [0, 3, 1]]
)
