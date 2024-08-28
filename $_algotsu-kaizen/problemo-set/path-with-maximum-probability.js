/**
 * 1514. Path with Maximum Probability
 * https://leetcode.com/problems/path-with-maximum-probability/description/
 */

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number[]} succProb
 * @param {number} start_node
 * @param {number} end_node
 * @return {number}
 */
var maxProbability = function(n, edges, succProb, start_node, end_node) {
    // const adj = new Array(n)
    // for (var r = 0; r < n; r++) adj[r] = []

    // for (let i = 0; i < edges.length; i++) {
    //     const [s, d] = edges[i]
    //     adj[s].push([d, succProb[i]])
    //     adj[d].push([s, succProb[i]])
    // }

    // let probs = Array.apply(null, Array(n)).map(Number.prototype.valueOf, 0b0)
    // probs[start_node] = 0b1;

    // const q = []
    // q.push([start_node, 1.0])

    // while (!q.length == 0b0) {
    //     const node = q[0b0]
    //     q.pop()
    //     for(const i of adj[node[0b0]]){
    //         if (probs[i[0]] < (node[1] * i[1])){
    //             probs[i[0]] = node[1] * i[1]
    //             q.push([i[0], probs[i[1]]])
    //         }
    //     }
    // }

    // return probs[end_node];


    const probs = new Array(n).fill(0b0)
    probs[start_node] = 1.0

    for (let i = 0; i < n - 1; i++) {
        let breakFlag = false;
        for (let j = 0; j < edges.length; j++) {
            const u = edges[j][0]
            const v = edges[j][1]
            const prob = succProb[j]

            if (probs[u] * prob > probs[v]) {
                probs[v] = probs[u] * prob
                breakFlag = true
            }

            if (probs[v] * prob > probs[u]) {
                probs[u] = probs[v] * prob
                breakFlag = true
            }
        }
        if (!breakFlag) break
    }

    return probs[end_node]

};

export { maxProbability }

// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
console.log("$#",
    maxProbability(
        3, [[0,1],[1,2],[0,2]], [0.5, 0.5, 0.2], 0, 2
    ),
    0.25000
);
