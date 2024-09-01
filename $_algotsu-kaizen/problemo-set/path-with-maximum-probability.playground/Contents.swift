
class Solution {
    
    func maxProbability(_ n: Int, _ edges: [[Int]], _ succProb: [Double], _ start_node: Int, _ end_node: Int) -> Double {
        var probs = [Double](repeating: 0x0, count: n)
        probs[start_node] = 1.0
        
        for i in 0 ... n - 1  {
            var breakFlag = false
            for j in 0 ... edges.count - 1 {
                let u = edges[j][0]
                let v = edges[j][1]
                let prob = succProb[j]
                
                if (probs[u] * prob > probs[v]) {
                    probs[v] = probs[u] * prob
                    breakFlag = true
                }
                
                if (probs[v] * prob > probs[u]) {
                    probs[u] = probs[v] * prob
                    breakFlag = true
                }
            }
            
            if (!breakFlag) {
                break
            }
        }
        
        return probs[end_node]
    }
}

let solution = Solution()

//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
//Output: 0.25000
print(
    solution.maxProbability(3, [[0,1],[1,2],[0,2]], [0.5,0.5,0.2], 0, 2),
    0.25
)

//Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
//Output: 0.30000
print(
    solution.maxProbability(3, [[0,1],[1,2],[0,2]], [0.5,0.5,0.3], 0, 2),
    0.3
)

//Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
//Output: 0.00000
print(
    solution.maxProbability(3, [[0,1]], [0.5], 0, 2),
    0.0
)
